/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:07:48 by vpac              #+#    #+#             */
/*   Updated: 2023/05/12 14:23:07 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw3d(t_cub3d *data, t_ray_data ray)
// {
// 	int			lineH;
// 	float		disW;
// 	float		lineO;
// 	float		ca;
// 	t_pixel_pos	dst;

// 	ca = data->player.pa - ray.ra;
// 	secure_angle(ca);
// 	disW = pitagora(data->player.px, data->player.py, ray.rx, ray.ry);
// 	disW = disW * cos(ca);
// 	lineO = (RES * WINDOW_HEIGHT) - disW / 2.0;
// 	lineH = (RES * WINDOW_HEIGHT) / disW;
// 	if (lineH > WINDOW_HEIGHT)
// 		lineH = WINDOW_HEIGHT;

// }
