/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:13:32 by vpac              #+#    #+#             */
/*   Updated: 2023/05/05 17:32:29 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_distance_to_hor_wall(t_player_data *player, t_ray_data *ray,
						float aTan)
{
	if (ray->ra > PI2 && ray->ra < PI3)
	{
		ray->rx = ((((int)player->px >> 6) << 6) - 0.0001);
		ray->ry = (player->px - ray->rx * aTan + player->py);
		ray->xo = RES;
		ray->yo = -1.0 * ray->xo / aTan;
	}
	if (ray->ra < PI2 || ray->ra > PI3)
	{
		ray->rx = ((((int)player->px >> 6) << 6) + RES);
		ray->ry = (player->px - ray->rx * aTan + player->py);
		ray->xo = RES;
		ray->yo = -1.0 * ray->xo / aTan;
	}
	if (ray->ra == 0 || ray->ra == PI)
	{
		ray->ry = player->py;
		ray->rx = player->px;
	}
}

t_ray_data	*check_for_vertical_wall(t_cub3d *data, t_ray_data *ray_elem)
{
	t_ray_data		*ray;
	t_player_data	*player;
	float			aTan;
	int				ok;

	ok = 0;
	aTan = -1.0 * tan(ray->ra);
	player = &(data->player);
	ray = ray_elem;
	get_distance_to_hor_wall(player, data, aTan);
	while (!ok)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * data->parse.map_w + ray->mx;
		if (ray->mp > 0 && ray->mp < data->parse.map_w * data->parse.map_h
		&& data->parse.map[ray->mp] == 2)
			ok = 1;
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
		}
	}
	return (ray);
}
