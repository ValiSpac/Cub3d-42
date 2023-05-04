/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:36:39 by vpac              #+#    #+#             */
/*   Updated: 2023/05/04 16:42:28 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	ray_list = malloc(sizeof(t_ray_data) * (player->fov));
	ray_list[i].ra = player->pa - (DEG * player->fov / 2.0);
	secure_angle(ray_list[i].ra);
	while (i < (player->fov * RAY_PER_DEGREE))
	{
		horizontal_inter = check_for_horizontal_wall(data, &ray_list[i]);
	//	vertical_inter = check_for_vertical_wall(ray_list[i]);
	//	ray_list[i] = check_for_shortest_line(ray_list[i]);
	//	draw_3d(ray_list[i]);
		ray_list[i++].ra += DEG / RAY_PER_DEGREE;
		secure_angle(ray_list[i].ra);
	}
}
