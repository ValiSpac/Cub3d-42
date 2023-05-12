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

void		draw_texture_pillar(t_cub3d *data, t_ray_data ray,
	t_pixel_pos src, t_pixel_pos dst);
t_texture	*get_ray_texture(t_cub3d *data, t_ray_data ray);
int			get_ray_hit_pos(t_ray_data ray);
void	frame_draw_texture_line(t_cub3d *data, t_texture *texture,
	t_pixel_pos window_src, int window_line_h, int texture_x);

int	texture_get_pixel(t_texture texture, t_pixel_pos p)
{
	char	*pixel;

	if (p.x < 0 || p.y < 0 || p.x >= texture.width || p.y >= texture.height)
		return (0);
	pixel = texture.frame.addr + (4) * (p.x + p.y * texture.width);
	return (*(int *)pixel);
}


void	draw3d(t_cub3d *data, t_ray_data ray, int ray_num)
{
	int			lineH;
	int			disW;
	int			lineO;
	float		ca;
	int			i;
	t_pixel_pos	ray_pixel;
	t_pixel_pos	dst;

	i = 0;
	ca = data->player.pa - ray.ra;
	secure_angle(ca);
	disW = (int)pitagora(data->player.px, data->player.py, ray.rx, ray.ry);
	disW = disW * cos(ca);
	lineH = (RES * WINDOW_HEIGHT) / disW;
	if (lineH > WINDOW_HEIGHT)
		lineH = WINDOW_HEIGHT;

	////
	lineO = WINDOW_HEIGHT - (WINDOW_HEIGHT / 2 - lineH / 2);
	ray_pixel.x = ray_num * (int)(WINDOW_WIDTH / (data->player.fov * RAY_PER_DEGREE));
	ray_pixel.y = lineO - lineH;
	dst.x = ray_pixel.x;
	dst.y = lineO;
	dst.x += (int)(WINDOW_WIDTH / (data->player.fov * RAY_PER_DEGREE));
	draw_texture_pillar(data, ray, ray_pixel, dst);
	////

	lineO = WINDOW_HEIGHT - (WINDOW_HEIGHT / 2 - lineH / 2);
	ray_pixel.x = ray_num * (int)(WINDOW_WIDTH / (data->player.fov * RAY_PER_DEGREE));
	ray_pixel.y = lineO;
	dst.x = ray_pixel.x;
	dst.y = ray_pixel.y - lineH;
	while (i < (int)(WINDOW_WIDTH / (data->player.fov * RAY_PER_DEGREE)))
	{
		ray_pixel.x += 1;
		dst.x = ray_pixel.x;
		//frame_draw_line(data->frame, ray_pixel, dst, 16711680);
		i++;
	}
}

void	draw_texture_pillar(t_cub3d *data, t_ray_data ray, t_pixel_pos src, t_pixel_pos dst)
{
	t_texture	*texture;
	int			ray_hit_pos;
	int			width;
	int			height;

	(void)data;
	(void)src;
	(void)dst;
	(void)texture;
	(void)ray_hit_pos;
	(void)width;
	texture = get_ray_texture(data, ray);
	ray_hit_pos = get_ray_hit_pos(ray);
	width = dst.x - src.x;
	height = dst.y - src.y;
	frame_draw_texture_line(data, texture, src, height, ray_hit_pos);
}

void	frame_draw_texture_line(t_cub3d *data, t_texture *texture,
	t_pixel_pos window_src, int window_line_h, int texture_x)
{
	t_pixel_pos	window_pos;
	t_pixel_pos	texture_pos;
	int	i;

	(void)window_line_h;
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


int	get_ray_hit_pos(t_ray_data ray)
{
	if (ray.hit_horizontal)
	{
		if (ray.yo > 0.0)
			return (RES - ((int)ray.rx % RES) - 1);
		return (((int)ray.rx % RES));
	}
	if (ray.xo > 0.0)
		return (RES - ((int)ray.ry % RES) - 1);
	return (((int)ray.ry % RES));
}

t_texture	*get_ray_texture(t_cub3d *data, t_ray_data ray)
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
