/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:31:28 by vpac              #+#    #+#             */
/*   Updated: 2023/05/04 16:49:16 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray_data	check_for_horizontal_wall(t_cub3d *data, t_ray_data *ray_elem)
{
	t_ray_data		*ray;
	t_player_data	*player;
	float			aTan;

	aTan = -1.0 * (1.0 / tan(ray->ra));
	player = &(data->player);
	ray = ray_elem;
	if (ray->ra > PI)
	{
		ray->ry = ((((int)player->py >> 6) << 6) - 0.0001);
		ray->rx = (player->py - ray->ry * aTan + player->px);
		ray->yo = RES;
		ray->xo = -1.0 * ray->yo / aTan;
	}
	else if (ray->ra < PI)
	{
		//code
	}
}
