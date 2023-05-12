/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:20:35 by lopayet-          #+#    #+#             */
/*   Updated: 2023/05/12 14:22:52 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MINIMAP_SCALE WINDOW_WIDTH / 128
// void	frame_draw_line(t_frame frame,
// 	t_pixel_pos p1, t_pixel_pos p2, int color);

void	frame_draw_block(t_cub3d *cub3d, int y_start, int x_start, int color);
void	frame_draw_2d_map(t_cub3d *cub3d);
void	frame_draw_player(t_cub3d *cub3d, float y_start, float x_start);
void	frame_draw_rays(t_cub3d *cub3d);


void	frame_draw_minimap(t_cub3d *cub3d)
{
	clear_frame(cub3d->frame);
	frame_draw_2d_map(cub3d);
	frame_draw_rays(cub3d);
	frame_draw_player(cub3d, cub3d->player.pdy / 64.0, cub3d->player.pdx / 64.0);
	put_frame_to_window(cub3d);
}

void	frame_draw_rays(t_cub3d *cub3d)
{
	int			i;
	float		coef;
	t_pixel_pos	dst;
	t_pixel_pos	player_pos;

	coef = (float)MINIMAP_SCALE / (float)RES;
	player_pos.x = cub3d->player.pdx * coef;
	player_pos.y = cub3d->player.pdy * coef;
	i = 0;
	while (i < cub3d->ray_count)
	{
		dst.x = (int)(cub3d->ray_list[i].rx * coef);
		dst.y = (int)(cub3d->ray_list[i].ry * coef);
		frame_draw_line(cub3d->frame, dst, player_pos, 255);
		i++;
	}
}

void	frame_draw_2d_map(t_cub3d *cub3d)
{
	int	y;
	int	x;

	y = 0;
	while (y < cub3d->parse.map_h)
	{
		x = 0;
		while (x < cub3d->parse.map_w)
		{
			if (cub3d->parse.map[y][x] == 1)
				frame_draw_block(cub3d, y, x, 4473924);
			if (cub3d->parse.map[y][x] == 2)
				frame_draw_block(cub3d, y, x, 16777215);
			x++;
		}
		y++;
	}
}

void	frame_draw_player(t_cub3d *cub3d, float y_start, float x_start)
{
	t_pixel_pos	pos;
	int			x_end;
	int			y_end;

	x_end = x_start * MINIMAP_SCALE + MINIMAP_SCALE / 10;
	y_end = y_start * MINIMAP_SCALE + MINIMAP_SCALE / 10;
	pos.y = y_start * MINIMAP_SCALE - MINIMAP_SCALE / 10;
	while (pos.y < y_end)
	{
		pos.x = x_start * MINIMAP_SCALE - MINIMAP_SCALE / 10;
		while (pos.x < x_end)
		{
			frame_draw_pixel(cub3d->frame, pos, 16776960);
			pos.x++;
		}
		pos.y++;
	}
}

void	frame_draw_block(t_cub3d *cub3d, int y_start, int x_start, int color)
{
	t_pixel_pos	pos;
	int			x_end;
	int			y_end;

	x_end = x_start * MINIMAP_SCALE + MINIMAP_SCALE - 1;
	y_end = y_start * MINIMAP_SCALE + MINIMAP_SCALE - 1;
	pos.y = y_start * MINIMAP_SCALE;
	while (pos.y < y_end)
	{
		pos.x = x_start * MINIMAP_SCALE;
		while (pos.x < x_end)
		{
			frame_draw_pixel(cub3d->frame, pos, color);
			pos.x++;
		}
		pos.y++;
	}
}
