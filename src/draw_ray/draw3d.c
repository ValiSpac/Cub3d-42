/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:07:48 by vpac              #+#    #+#             */
/*   Updated: 2023/05/12 17:44:11 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_texture_pillar(t_cub3d *data, t_ray_data ray,
	t_pixel_pos src, t_pixel_pos dst);
static t_texture	*get_ray_texture(t_cub3d *data, t_ray_data ray);
static int			get_ray_hit_pos(t_ray_data ray);
static void	frame_draw_texture_line(t_cub3d *data, t_texture *texture,
	t_pixel_pos window_src, int window_line_h, int texture_x);

void	draw3d(t_cub3d *data, t_ray_data ray, int ray_num)
{
	int			lineH;
	int			disW;
	int			lineO;
	float		ca;
	t_pixel_pos	ray_pixel;
	t_pixel_pos	dst;

	ca = data->player.pa - ray.ra;
	secure_angle(ca);
	disW = (int)pitagora(data->player.px, data->player.py, ray.rx, ray.ry);
	disW = disW * cos(ca);
	lineH = (RES * WINDOW_HEIGHT) / disW;
	if (lineH > WINDOW_HEIGHT)
		lineH = WINDOW_HEIGHT;
	lineO = WINDOW_HEIGHT - (WINDOW_HEIGHT / 2 - lineH / 2);
	ray_pixel.x = ray_num * (int)(WINDOW_WIDTH / (data->player.fov * RAY_PER_DEGREE));
	ray_pixel.y = lineO - lineH;
	dst.x = ray_pixel.x;
	dst.y = lineO;
	dst.x += (int)(WINDOW_WIDTH / (data->player.fov * RAY_PER_DEGREE));
	draw_texture_pillar(data, ray, ray_pixel, dst);
}

static void	draw_texture_pillar(t_cub3d *data, t_ray_data ray, t_pixel_pos src, t_pixel_pos dst)
{
	t_texture	*texture;
	int			height;
	int			ray_hit_pos;

	texture = get_ray_texture(data, ray);
	ray_hit_pos = get_ray_hit_pos(ray);
	height = dst.y - src.y;
	while (src.x < dst.x)
	{
		frame_draw_texture_line(data, texture, src, height, ray_hit_pos);
		src.x++;
	}
}

static void	frame_draw_texture_line(t_cub3d *data, t_texture *texture,
	t_pixel_pos window_src, int window_line_h, int texture_x)
{
	t_pixel_pos	window_pos;
	t_pixel_pos	texture_pos;
	int	i;

	i = 0;
	window_pos.x = window_src.x;
	window_pos.y = window_src.y;
	texture_pos.x = texture_x;
	while (i < window_line_h)
	{
		texture_pos.y = (float)i / window_line_h * texture->height;
		frame_draw_pixel(data->frame, window_pos, texture_get_pixel(*texture, texture_pos));
		window_pos.y++;
		i++;
	}
}

static int	get_ray_hit_pos(t_ray_data ray)
{
	if (ray.hit_horizontal)
	{
		if (ray.yo > 0.0)
			return (((int)ray.rx % RES));
		return (RES - ((int)ray.rx % RES) - 1);
	}
	if (ray.xo > 0.0)
		return (RES - ((int)ray.ry % RES) - 1);
	return (((int)ray.ry % RES));
}

static t_texture	*get_ray_texture(t_cub3d *data, t_ray_data ray)
{
	if (ray.hit_horizontal)
	{
		if (ray.yo > 0.0)
			return (&data->S_texture);
		return (&data->N_texture);
	}
	if (ray.xo > 0.0)
		return (&data->E_texture);
	return (&data->W_texture);
}
