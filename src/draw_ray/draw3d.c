/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopayet- <lopayet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:07:48 by vpac              #+#    #+#             */
/*   Updated: 2023/05/10 17:45:36 by lopayet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw3d(t_cub3d *data, t_ray_data ray)
{
	float	disW;

	disW = 10000000;
	disW = pitagora(data->player.px, data->player.py, ray.rx, ray.ry);
	(void)disW;
	//printf("OFSET x=%f, y=%f\n", ray.xo, ray.yo);
}
