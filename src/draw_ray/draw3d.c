/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopayet- <lopayet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:07:48 by vpac              #+#    #+#             */
/*   Updated: 2023/06/17 11:43:36 by lopayet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

struct s_texturing_data
{
	t_pixel_pos	src;
	t_pixel_pos	dst;
};

static void		draw_texture_pillar(t_cub3d *data, t_ray_data ray,
					t_pixel_pos src, t_pixel_pos dst, int t_off);
static t_texture	*get_ray_texture(t_cub3d *data, t_ray_data ray);
static int			get_ray_hit_pos(t_ray_data ray);
static void	frame_draw_texture_line(t_cub3d *data, t_texture *texture,
	t_pixel_pos window_src, int window_line_h, int texture_x, int t_off);

void	draw3d(t_cub3d *data, t_ray_data ray, int ray_num)
{
	int			lineh;
	float		disw;
	int			lineo;
	float		ca;
	t_pixel_pos	ray_pixel;
	t_pixel_pos	dst;
	int			t_off;

	t_off = 0;
	ca = data->player.pa - ray.ra;
	disw = (cos(ca)) * (cos(ray.ra) * (ray.rx - data->player.pdx)
		- sin(ray.ra) * (ray.ry - data->player.pdy));
	lineh = (RES * WINDOW_HEIGHT) / disw;
	if (lineh > WINDOW_HEIGHT)
	{
		t_off = (lineh - WINDOW_HEIGHT) / 2;
		lineh = WINDOW_HEIGHT;
	}
	lineo = WINDOW_HEIGHT - (WINDOW_HEIGHT / 2 - lineh / 2);
	ray_pixel.x = ray_num;
	ray_pixel.y = lineo - lineh;
	dst.x = ray_pixel.x + 1;
	dst.y = lineo;
	draw_texture_pillar(data, ray, ray_pixel, dst, t_off);
}

static void	draw_texture_pillar(t_cub3d *data, t_ray_data ray, t_pixel_pos src, t_pixel_pos dst, int t_off)
{
	t_texture	*texture;
	int			height;
	int			ray_hit_pos;

	texture = get_ray_texture(data, ray);
	ray_hit_pos = get_ray_hit_pos(ray);
	height = dst.y - src.y;
	while (src.x < dst.x)
	{
		frame_draw_texture_line(data, texture, src, height, ray_hit_pos, t_off);
		src.x++;
	}
}

static void	frame_draw_texture_line(t_cub3d *data, t_texture *texture,
	t_pixel_pos window_src, int window_line_h, int texture_x, int t_off)
{
	t_pixel_pos	window_pos;
	t_pixel_pos	texture_pos;
	int	i;

	(void)t_off;
	i = 0;
	window_pos.x = window_src.x;
	window_pos.y = window_src.y;
	texture_pos.x = texture_x;
	while (i < window_line_h)
	{
		texture_pos.y = (float)(i + t_off) / (window_line_h + t_off * 2) * (texture->height);
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
			return (RES - ((int)ray.rx % RES) - 1);
		return (((int)ray.rx % RES));
	}
	if (ray.xo > 0.0)
		return (((int)ray.ry % RES));
	return (RES - ((int)ray.ry % RES) - 1);
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
		return (&data->W_texture);
	return (&data->E_texture);
}
