/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopayet- <lopayet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:37:17 by lopayet-          #+#    #+#             */
/*   Updated: 2023/05/04 14:37:19 by lopayet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keydown(int keysym, t_cub3d *cub3d)
{
	if (keysym == XK_Escape)
		cub3d->exit = 1;
	return (0);
}

int	handle_window_kill(t_cub3d *cub3d)
{
	cub3d->exit = 1;
	return (0);
}

int	handle_mousedown(int button, int x, int y, t_cub3d *cub3d)
{
	if (button == 1)
	{
	}
	if (button == 4 || button == 5)
	{
	}
	(void)x;
	(void)cub3d;
	(void)y;
	return (0);
}

int	handle_mouseup(int button, int x, int y, t_cub3d *cub3d)
{
	if (button == 1)
	{
	}
	(void)x;
	(void)cub3d;
	(void)y;
	return (0);
}

int	handle_mouse_move(int x, int y, t_cub3d *cub3d)
{
	(void)x;
	(void)y;
	(void)cub3d;
	return (0);
}
