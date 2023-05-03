/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopayet- <lopayet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:22:01 by lopayet-          #+#    #+#             */
/*   Updated: 2023/04/29 17:17:14 by lopayet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>

# include "parse.h"

# define WINDOW_WIDTH 2400
# define WINDOW_HEIGHT 1400

typedef struct s_frame		t_frame;
struct s_frame {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

typedef struct s_cub3d		t_cub3d;
struct s_cub3d
{
	void			*mlx;
	void			*window;
	t_parse_data	data;
	t_frame			frame;
};


// cub3d
int		cub3d_init_mlx(t_cub3d *cub3d);
void	cub3d_destroy_mlx(t_cub3d cub3d);

// common_utils
void	print_err(char *str);

#endif
