/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:40:45 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/12 09:41:52 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

typedef struct s_data_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data_img;

typedef struct s_data_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_data_img		*img_array[10];
}	t_data_mlx;

/*	parsing.c	*/
int				ft_scan_map_and_print_error(char **tab_line);
int				ft_is_map_correct(int fd_map);
/*	parsing2.c	*/
int				ft_is_char_valid(char c);
int				ft_is_closed_rectangle(char	**line_array);
int				ft_is_character_among_array(char **line_array, int c);
int				ft_is_there_nonvalid_char(char **line_array);
/*	readfile.c	*/
char			*ft_fd_to_str(int fd);
void			ft_free_array(char **array);
/*	myMlx.c		*/
void			my_mlx_pixel_put(t_data_img *data_img, int x, int y, int color);
t_data_mlx		*ft_create_mlx_data(int width, int height, char *title);
t_data_img		*ft_create_new_image(void *mlx, int width, int height);
void			ft_add_image(t_data_mlx *mlx_data, t_data_img *new_img);
void			ft_close_mlx_data(t_data_mlx *mlx_data);
void			ft_display_mlx_image(t_data_mlx *mlx_data, t_data_img *img, int posx, int posy);
#endif




