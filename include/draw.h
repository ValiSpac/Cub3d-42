/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:06:22 by vpac              #+#    #+#             */
/*   Updated: 2023/05/04 16:45:38 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "parse.h"
# include <math.h>
# define PI 3.141592
# define PI2 (PI / 2.0)
# define PI3 ((3.0 * PI) / 2.0)
# define E 0
# define W PI
# define N PI2
# define S PI3
# define RES 64
# define DEG 0.017453
# define RAY_PER_DEGREE 1

typedef struct s_player_data		t_player_data;
struct s_player_data
{
	float	fov;
	float	pdx;//player x coord
	float	pdy;//player y coord
	int		px;//grid x position
	int		py;//grid y position
	float	pa;//player angle
};

typedef struct s_ray_data		t_ray_data;
struct s_ray_data
{
	float	ra;
	float	rx;//ray x coord
	float	ry;//ray y coord
	float	xo;//ray x offset
	float	yo;//ray y offset
};


#endif
