/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:31:28 by vpac              #+#    #+#             */
/*   Updated: 2023/05/11 16:14:12 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_distance_to_hor_wall(t_player_data *player, t_ray_data *ray,
						float aTan, int *ok)
{
	if (sin(ray->ra) > 0.001)
	{
		ray->ry = (((int)player->pdy >> 6) << 6) - 0.0001;
		ray->rx = ((player->pdy - ray->ry) * aTan + player->pdx);
		ray->yo = -RES;
		ray->xo = -ray->yo * aTan;
	}
	else if (sin(ray->ra) < -0.001)
	{
		ray->ry = (((int)player->pdy >> 6) << 6) + RES;
		ray->rx = ((player->pdy - ray->ry) * aTan + player->pdx);
		ray->yo = RES;
		ray->xo = -ray->yo * aTan;
	}
	else
	{
		ray->ry = player->py;
		ray->rx = player->px;
		ray->yo = 0;
		ray->xo = RES;
		*ok = 0;
	}
}

static int	is_in_map(int x, int y, int w, int h)
{
	return (
		(x > 0 && y > 0) &&
		(x < w && y < h)
	);
}

t_ray_data	*check_for_horizontal_wall(t_cub3d *data, t_ray_data *ray_elem)
{
	t_ray_data		*ray;
	t_player_data	*player;
	float			aTan;
	int				ok;

	ok = 0;
	ray = ray_elem;
	aTan = 1.0 / tan(ray->ra);
	player = &(data->player);
	get_distance_to_hor_wall(player, ray, aTan, &ok);
	while (!ok)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		if ((is_in_map(ray->mx, ray->my, data->parse.map_w, data->parse.map_h)
		&& data->parse.map[ray->my][ray->mx] == 2)
		|| !is_in_map(ray->mx, ray->my, data->parse.map_w, data->parse.map_h))
			ok = 1;
		if (!ok)
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
		}
	}
	return (ray);
}
