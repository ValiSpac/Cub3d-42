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
	lineO = WINDOW_HEIGHT - (WINDOW_HEIGHT / 2 - lineH / 2);
	ray_pixel.x = ray_num * (int)(WINDOW_WIDTH / (data->player.fov * RAY_PER_DEGREE));
	ray_pixel.y = lineO;
	while (i < (int)(WINDOW_WIDTH / (data->player.fov * RAY_PER_DEGREE)))
	{
		ray_pixel.x += 1;
		dst.x = ray_pixel.x;
		dst.y = ray_pixel.y - lineH;
		frame_draw_line(data->frame, ray_pixel, dst, 16711680);
		i++;
	}
}
