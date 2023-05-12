
#include "cub3d.h"

int	load_textures(t_cub3d *cub3d)
{
	cub3d->N_texture.frame.mlx_img = mlx_xpm_file_to_image(cub3d->mlx,
		cub3d->parse.NO, &cub3d->N_texture.width, &cub3d->N_texture.height);
	cub3d->S_texture.frame.mlx_img = mlx_xpm_file_to_image(cub3d->mlx,
		cub3d->parse.SO, &cub3d->S_texture.width, &cub3d->S_texture.height);
	cub3d->W_texture.frame.mlx_img = mlx_xpm_file_to_image(cub3d->mlx,
		cub3d->parse.WE, &cub3d->W_texture.width, &cub3d->W_texture.height);
	cub3d->E_texture.frame.mlx_img = mlx_xpm_file_to_image(cub3d->mlx,
		cub3d->parse.EA, &cub3d->E_texture.width, &cub3d->E_texture.height);
	if (!cub3d->N_texture.frame.mlx_img || !cub3d->S_texture.frame.mlx_img
		|| !cub3d->W_texture.frame.mlx_img || !cub3d->E_texture.frame.mlx_img)
		return (1);
	cub3d->N_texture.frame.addr = mlx_get_data_addr(cub3d->N_texture.frame.mlx_img,
			&(cub3d->N_texture.frame.bpp), &(cub3d->N_texture.frame.line_len),
			&(cub3d->N_texture.frame.endian));
	cub3d->S_texture.frame.addr = mlx_get_data_addr(cub3d->S_texture.frame.mlx_img,
			&(cub3d->S_texture.frame.bpp), &(cub3d->S_texture.frame.line_len),
			&(cub3d->S_texture.frame.endian));
	cub3d->W_texture.frame.addr = mlx_get_data_addr(cub3d->W_texture.frame.mlx_img,
			&(cub3d->W_texture.frame.bpp), &(cub3d->W_texture.frame.line_len),
			&(cub3d->W_texture.frame.endian));
	cub3d->E_texture.frame.addr = mlx_get_data_addr(cub3d->E_texture.frame.mlx_img,
			&(cub3d->E_texture.frame.bpp), &(cub3d->E_texture.frame.line_len),
			&(cub3d->E_texture.frame.endian));
	return (0);
}

int	are_textures_valid(t_cub3d *cub3d)
{
	if (cub3d->N_texture.width != cub3d->N_texture.height
		|| cub3d->S_texture.width != cub3d->S_texture.height
		|| cub3d->W_texture.width != cub3d->W_texture.height
		|| cub3d->E_texture.width != cub3d->E_texture.height)
		return (0);
	if (cub3d->N_texture.width != cub3d->S_texture.width
		|| cub3d->S_texture.width != cub3d->W_texture.width
		|| cub3d->W_texture.width != cub3d->E_texture.width)
		return (0);
	if (cub3d->N_texture.width != RES)
		return (0);
	return (1);
}

int	get_texture_x_start(t_cub3d *cub3d, int res_pos)
{
	(void)cub3d;
	return (res_pos);
}
