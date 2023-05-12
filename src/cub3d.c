/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopayet- <lopayet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:33 by lopayet-          #+#    #+#             */
/*   Updated: 2023/05/10 15:55:57 by lopayet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_hooks(t_cub3d *cub3d);

int	main(int argc, char **argv)
{
	t_cub3d cub3d;

	(void)argc;
	if (cub3d_init_mlx(&cub3d) != 0)
		return (print_err("MLX error."), 1);
	if (parse_file(argv[1], &cub3d.parse) != 0)
		return (print_parsing_error(cub3d.parse.parse_errno),
			cub3d_destroy_mlx(cub3d), free_parse_data(&cub3d.parse), 2);
	init_player_data(&cub3d);
	set_hooks(&cub3d);
	mlx_loop(cub3d.mlx);
	free_parse_data(&cub3d.parse);
	cub3d_destroy_mlx(cub3d);
	return (0);
}

static int	cub3d_loop(t_cub3d *cub3d)
{
	cub3d->ray_list = 0;
	draw_ray(cub3d);
	update_player_pos(cub3d);
	frame_draw_minimap(cub3d);
	if (cub3d->ray_list)
		free(cub3d->ray_list);
	//printf("nigg=%d;%d\n", cub3d->player.move_pa_right, cub3d->player.move_pa_left);
	if (cub3d->exit)
		mlx_loop_end(cub3d->mlx);
	return (0);
}

static void	set_hooks(t_cub3d *cub3d)
{
	cub3d->exit = 0;
	mlx_loop_hook(cub3d->mlx, &cub3d_loop, cub3d);
	mlx_hook(cub3d->window, KeyPress, KeyPressMask, &handle_keydown, cub3d);
	mlx_hook(cub3d->window, KeyRelease, KeyReleaseMask, &handle_keyup, cub3d);
	mlx_hook(cub3d->window, DestroyNotify, NoEventMask, &handle_window_kill, cub3d);
}
