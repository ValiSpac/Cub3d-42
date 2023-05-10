/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:07:48 by vpac              #+#    #+#             */
/*   Updated: 2023/05/10 13:19:45 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw3d(t_player_data *p, t_ray_data *ray)
{
	float	disW;
	float	lineH;
	float	ca;

	disW = 10000000;
	disW = pitagora(p->px, p->py, ray->rx, ray->ry, ray->ra);
	ca = p->pa - ray->ra;
	secure_angle(ca);

}
