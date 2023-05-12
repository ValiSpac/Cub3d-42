/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:07:48 by vpac              #+#    #+#             */
/*   Updated: 2023/05/11 17:26:00 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw3d(t_cub3d *data, t_ray_data ray)
{
	int			lineH;
	float		disW;
	float		ca;
	t_pixel_pos	dst;

	disW = 0;
	disW = pitagora(data->player.px, data->player.py, ray.rx, ray.ry);
	ca = data->player.pa - ray.ra;
	secure_angle(ca);
	disW = disW * cos(ca);
	lineH = (RES * WINDOW_HEIGHT) / disW;
	if (lineH > WINDOW_HEIGHT)
		lineH = WINDOW_HEIGHT;

}
