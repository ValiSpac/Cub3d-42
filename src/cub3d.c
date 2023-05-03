/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopayet- <lopayet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:33 by lopayet-          #+#    #+#             */
/*   Updated: 2023/04/29 20:44:47 by lopayet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MLX_ERROR 1

#include <stdio.h>//////////////////////////

int	main(int argc, char **argv)
{
	t_cub3d cub3d;

	(void)argc;
	(void)argv;
	if (cub3d_init_mlx(&cub3d) != 0)
		return (print_err("MLX error."), MLX_ERROR);
	if (parse_file(argv[1], &cub3d.data) != 0)
		return (print_parsing_error(cub3d.data.parse_errno),
			cub3d_destroy_mlx(cub3d), free_parse_data(&cub3d.data), 1);
	dump_map(&cub3d.data);
	printf("NO='%s'\n", cub3d.data.NO);
	printf("SO='%s'\n", cub3d.data.SO);
	printf("WE='%s'\n", cub3d.data.WE);
	printf("EA='%s'\n", cub3d.data.EA);
	printf("FC=%d\n", cub3d.data.FC);
	printf("CC=%d\n", cub3d.data.CC);
	free_parse_data(&cub3d.data);
	//set_hooks(&cub3d);
	//mlx_loop(cub3d.mlx);
	cub3d_destroy_mlx(cub3d);
	return (0);
}

int	cub3d_init_mlx(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (cub3d->mlx == NULL)
		return (1);
	cub3d->window = mlx_new_window(cub3d->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (cub3d->window == NULL)
		return (free(cub3d->mlx), 1);
	cub3d->frame.mlx_img = mlx_new_image(cub3d->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (cub3d->frame.mlx_img == NULL)
	{
		mlx_destroy_window(cub3d->mlx, cub3d->window);
		mlx_destroy_display(cub3d->mlx);
		return (free(cub3d->mlx), 1);
	}
	cub3d->frame.addr = mlx_get_data_addr(cub3d->frame.mlx_img,
			&(cub3d->frame.bpp), &(cub3d->frame.line_len), &(cub3d->frame.endian));
	if (cub3d->frame.addr == NULL)
	{
		mlx_destroy_window(cub3d->mlx, cub3d->window);
		mlx_destroy_image(cub3d->mlx, cub3d->frame.mlx_img);
		mlx_destroy_display(cub3d->mlx);
		return (free(cub3d->mlx), 1);
	}
	return (0);
}

void	cub3d_destroy_mlx(t_cub3d cub3d)
{
	mlx_destroy_window(cub3d.mlx, cub3d.window);
	mlx_destroy_image(cub3d.mlx, cub3d.frame.mlx_img);
	mlx_destroy_display(cub3d.mlx);
	free(cub3d.mlx);
}
