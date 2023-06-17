/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopayet- <lopayet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:30:30 by lopayet-          #+#    #+#             */
/*   Updated: 2023/06/17 10:51:53 by lopayet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_err(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
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
	if (cub3d.N_texture.frame.mlx_img)
		mlx_destroy_image(cub3d.mlx, cub3d.N_texture.frame.mlx_img);
	if (cub3d.S_texture.frame.mlx_img)
		mlx_destroy_image(cub3d.mlx, cub3d.S_texture.frame.mlx_img);
	if (cub3d.W_texture.frame.mlx_img)
		mlx_destroy_image(cub3d.mlx, cub3d.W_texture.frame.mlx_img);
	if (cub3d.E_texture.frame.mlx_img)
		mlx_destroy_image(cub3d.mlx, cub3d.E_texture.frame.mlx_img);
	mlx_destroy_display(cub3d.mlx);
	free(cub3d.mlx);
}

float	min_float(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}
