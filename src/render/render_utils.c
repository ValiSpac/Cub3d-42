/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopayet- <lopayet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:56:20 by lopayet-          #+#    #+#             */
/*   Updated: 2023/05/04 16:17:19 by lopayet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	is_pixel_outside_window(t_pixel_pos pixel)
{
	return (pixel.x < 0 || pixel.x > WINDOW_WIDTH
		|| pixel.x < 0 || pixel.x > WINDOW_WIDTH);
}

void	clear_frame(t_frame frame)
{
	char	*pixel;
	int		total;
	int		i;

	total = (WINDOW_WIDTH * WINDOW_HEIGHT);
	pixel = frame.addr;
	i = 0;
	while (i < total)
	{
		*(int *)pixel = 0;
		pixel += 4;
		i++;
	}
}

inline void	frame_draw_pixel(t_frame frame, t_pixel_pos p, int color)
{
	if (p.x < 0 || p.y < 0 || p.x >= WINDOW_WIDTH || p.y >= WINDOW_HEIGHT)
		return ;
	*(int *)(frame.addr + (4) * (p.x + p.y * WINDOW_WIDTH)) = color;
}

void	put_frame_to_window(t_cub3d *cub3d)
{
	mlx_clear_window(cub3d->mlx, cub3d->window);
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->frame.mlx_img, 0, 0);
}
