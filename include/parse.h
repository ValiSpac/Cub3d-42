/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopayet- <lopayet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:36:45 by lopayet-          #+#    #+#             */
/*   Updated: 2023/04/29 20:27:42 by lopayet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include <fcntl.h>

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

// get_data_utils
int		have_missing_data(t_parse_data *parse_data);
int		is_texture_line(char *line);
int		is_color_line(char *line);
int		is_color_valid(char **split);
// get_data
int		get_data_from_file(char *file, t_parse_data *parse_data);
// get_map_size
int		get_map_size_from_file(char *file, t_parse_data *parse_data);
// get_map
int		get_map_from_file(char *file, t_parse_data *parse_data);
// parse
void	free_parse_data(t_parse_data *parse_data);
int		parse_file(char *file, t_parse_data *parse_data);
void	dump_map(t_parse_data *parse_data);
// parse utils
int		line_is_map_content(char *line);
void	set_parse_errno(t_parse_data *parse_data, int n);
void	print_parsing_error(int	err);
// format check
int		file_format_error(char *file, t_parse_data *parse_data);
int		filename_has_cub_extension(char *filename);
// map check
int	is_map_valid(t_parse_data *parse_data);

#endif
