/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:11:06 by vpac              #+#    #+#             */
/*   Updated: 2023/05/12 13:53:30 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	get_pa_from_start_point(int start)
{
	if (start == 3)
		return (N);
	if (start == 4)
		return (S);
	if (start == 5)
		return (E);
	if (start == 6)
		return (W);
	return (-1.0);
}

void	init_player_data(t_cub3d	*data)
{
	t_player_data	*player;
	int				y;
	int				x;

	player = &(data->player);
	player->fov = 60;
	y = -1;
	while (++y < data->parse.map_h)
	{
		x = -1;
		while (++x < data->parse.map_w)
		{
			if (data->parse.map[y][x] >= 3)
			{
				player->pa = get_pa_from_start_point(data->parse.map[y][x]);
				player->py = y * RES + RES / 2;
				player->px = x * RES + RES / 2;
				player->pdy = y * RES + RES / 2;
				player->pdx = x * RES + RES / 2;
				data->parse.map[y][x] = 1;
			}
		}
	}
}
