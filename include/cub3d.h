/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:22:01 by lopayet-          #+#    #+#             */
/*   Updated: 2023/05/12 14:29:05 by vpac             ###   ########.fr       */
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
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

# define WINDOW_WIDTH 2400
# define WINDOW_HEIGHT 1400
# define PI 3.1495
# define PI2 1.5707
# define PI3 4.7123
# define E 0
# define W PI
# define N PI2
# define S PI3
# define RES 64
# define DEG 0.01749
# define RAY_PER_DEGREE 1

#define PLAYER_SPEED 5.0
#define PLAYER_ANGLE_SPEED 8.0
#define SLIDE_DISTANCE 0.3


typedef struct s_pixel_pos	t_pixel_pos;
struct s_pixel_pos {
	int	x;
	int	y;
};

typedef struct s_frame		t_frame;
struct s_frame {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

typedef struct s_parse_data	t_parse_data;
struct s_parse_data
{
	int		**map;
	int		map_h;
	int		map_w;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		FC;
	int		CC;
	int		FC_set;
	int		CC_set;
	int		parse_errno;
};

typedef struct s_player_data		t_player_data;
struct s_player_data
{
	float	fov;
	float	pdx;//player x coord
	float	pdy;//player y coord
	int		px;//grid x position
	int		py;//grid y position
	float	pa;//player angle
	int		move_forward;
	int		move_backward;
	int		move_right;
	int		move_left;
	int		move_pa_left;
	int		move_pa_right;
};

typedef struct s_ray_data		t_ray_data;
struct s_ray_data
{
	float	ra;
	float	rx;//ray x coord
	float	ry;//ray y coord
	float	xo;//ray x offset
	float	yo;//ray y offset
	int		mx;
	int		my;
	int		mp;
};

typedef struct s_cub3d		t_cub3d;
struct s_cub3d
{
	void			*mlx;
	void			*window;
	t_parse_data	parse;
	t_frame			frame;
	t_player_data	player;
	t_ray_data		*ray_list;
	int				ray_count;
	int				exit;
};


// cub3d

// common_utils
void		print_err(char *str);
int			cub3d_init_mlx(t_cub3d *cub3d);
void		cub3d_destroy_mlx(t_cub3d cub3d);

// events
int			handle_keydown(int keysym, t_cub3d *cub3d);
int			handle_keyup(int keysym, t_cub3d *cub3d);
int			handle_window_kill(t_cub3d *cub3d);

// controls
void		update_player_pos(t_player_data *data);

// parse/get_data_utils
int			have_missing_data(t_parse_data *parse_data);
int			is_texture_line(char *line);
int			is_color_line(char *line);
int			is_color_valid(char **split);
// parse/get_data
int			get_data_from_file(char *file, t_parse_data *parse_data);
// parse/get_map_size
int			get_map_size_from_file(char *file, t_parse_data *parse_data);
// parse/get_map
int			get_map_from_file(char *file, t_parse_data *parse_data);
// parse/parse
void		free_parse_data(t_parse_data *parse_data);
int			parse_file(char *file, t_parse_data *parse_data);
void		dump_map(t_parse_data *parse_data);
// parse/parse utils
int			line_is_map_content(char *line);
void		set_parse_errno(t_parse_data *parse_data, int n);
void		print_parsing_error(int	err);
// parse/format check
int			file_format_error(char *file, t_parse_data *parse_data);
int			filename_has_cub_extension(char *filename);
// parse/map check
int			is_map_valid(t_parse_data *parse_data);



// render/utils.c
void		frame_draw_pixel(t_frame frame, t_pixel_pos p, int color);
void		clear_frame(t_frame frame);
int			ft_abs(int n);
int			is_pixel_outside_window(t_pixel_pos pixel);
void		put_frame_to_window(t_cub3d *cub3d);
// render/draw_line.c
void		frame_draw_line(t_frame frame,
				t_pixel_pos p1, t_pixel_pos p2, int color);
// render/minimap.c
void		frame_draw_minimap(t_cub3d *cub3d);



//draw_ray/init_player.c
void		init_player_data(t_cub3d	*data);
//draw_ray/check_vertical.c
t_ray_data	*check_for_vertical_wall(t_cub3d *data, t_ray_data *ray_elem);
//draw_ray/check_horizontal.c
t_ray_data	*check_for_horizontal_wall(t_cub3d *data, t_ray_data *ray_elem);
//draw_ray/draw3d.c
void		draw3d(t_cub3d *data, t_ray_data ray);
//draw_ray/calc_ray.c
long		pitagora(float ax, float ay, float bx, float by);
void		secure_angle(float angle);
void		draw_ray(t_cub3d *data);


#endif
