/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:40:45 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/14 08:53:49 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

/* The following macro indicate
 * the standard square dimension of sprites
 */
# define SPRITE_PX_DIM 50

typedef struct s_data_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		*img_width;
	int		*img_height;
}			t_data_img;

typedef struct s_data_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_data_img		*img_array[10];
}	t_data_mlx;

typedef struct s_global
{
	t_data_mlx	*mlx_data;
	char		**fd_content;
	int			exit_code;
}	t_global;

/*	parsing.c	*/
int				ft_scan_map_and_print_error(char **tab_line);
int				ft_is_map_correct(char	**fd_content);
/*	parsing2.c	*/
int				ft_is_char_valid(char c);
int				ft_is_closed_rectangle(char	**line_array);
int				ft_is_character_among_array(char **line_array, int c);
int				ft_is_there_nonvalid_char(char **line_array);
/*	readfile.c	*/
char			*ft_fd_to_str(int fd);
void			ft_free_array(char **array);
int				ft_count_colums(char **fd_content);
int				ft_count_rows(char **fd_content);
char			**ft_fd_to_split_lines(int fd_map);
/*	game.c		*/
t_global		*ft_init_global_struct(char **fd_content,
					t_data_mlx *mlx_data, int exit_code);
int				ft_exit_game(t_global *mlx_global);
void			ft_start_game(char **fd_content);
/*	scene.c		*/
void			ft_map_to_scene(t_global *mlx_global, char map_element,
					int x, int y);
int				ft_exit_game(t_global *exit_struct);
void			ft_init_scene(t_global *mlx_global);

/*	my_mlx_utils.c		*/
void			my_mlx_pixel_put(t_data_img *data_img, int x, int y, int color);
t_data_mlx		*ft_create_mlx_data(int width, int height, char *title);
t_data_img		*ft_create_new_image(void *mlx, char *xpm_filepath);
void			ft_add_img(t_data_mlx *mlx_data, t_data_img *new_img,
					int index);
void			ft_charge_all_img(t_data_mlx *mlx_data);
/*	my_mlx_utils2.c		*/
void			ft_close_mlx_img(void *mlx, t_data_img *img);
void			ft_close_mlx_data(t_data_mlx *mlx_data);
#endif
