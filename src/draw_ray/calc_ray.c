/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:36:39 by vpac              #+#    #+#             */
/*   Updated: 2023/05/12 16:59:47 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


long	pitagora(float ax, float ay, float bx, float by)
{
	return(sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

static t_ray_data	check_for_shortest_line(t_player_data *p, t_ray_data h_inter,
						t_ray_data v_inter)
{
	float	disH;
	float	disV;

	disH = pitagora(p->px, p->py, h_inter.rx, h_inter.ry);
	disV = pitagora(p->px, p->py, v_inter.rx, v_inter.ry);
	if (disH > disV && disH != pitagora(p->px, p->py, p->px, p->py))
		return (v_inter);
	return (h_inter);
}

void	secure_angle(float angle)
{
	if (angle < 0.0)
		angle += 2.0 * PI;
	if (angle > 2.0 * PI)
		angle -= 2.0 * PI;
}

void	draw_ray(t_cub3d *data)
{
	t_player_data	*player;
	t_ray_data		*ray_list;
	t_ray_data		vertical_inter;
	t_ray_data		horizontal_inter;
	int				i;

	i = 0;
	player = &(data->player);
	ray_list = malloc(sizeof(t_ray_data) * (player->fov * RAY_PER_DEGREE) + 1);
	if (!ray_list)
		return ;
	ray_list[i].ra = player->pa - (DEG * player->fov / 2.0);
	secure_angle(ray_list[i].ra);
	while (i < (player->fov * RAY_PER_DEGREE))
	{
		horizontal_inter = *check_for_horizontal_wall(data, &ray_list[i]);
		vertical_inter = *check_for_vertical_wall(data, &ray_list[i]);
		ray_list[i] = check_for_shortest_line(&(data->player), horizontal_inter,
										vertical_inter);
		draw3d(data, ray_list[i], i);
		if (i + 1 < (player->fov * RAY_PER_DEGREE))
		{
			ray_list[i + 1].ra = ray_list[i].ra + DEG / RAY_PER_DEGREE;
			secure_angle(ray_list[i + 1].ra);
		}
		i++;
	}
	data->ray_count = player->fov * RAY_PER_DEGREE;
	data->ray_list = ray_list;
}
