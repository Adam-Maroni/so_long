/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:40:45 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/07 16:14:47 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

/*	parsing.c	*/
int		ft_scan_map_and_print_error(char **tab_line);
int		ft_is_map_correct(int fd_map);
/*	parsing2.c	*/
int		ft_is_char_valid(char c);
int		ft_is_closed_rectangle(char	**line_array);
int		ft_is_character_among_array(char **line_array, int c);
int		ft_is_there_nonvalid_char(char **line_array);
/*	readfile.c	*/
char	*ft_fd_to_str(int fd);
void	ft_free_array(char **array);
#endif
