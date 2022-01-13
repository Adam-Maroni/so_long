/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:22:21 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/13 07:58:52 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WINDOW_WIDTH 1531
#define WINDOW_HEIGHT 980

t_exit	*ft_init_exit_struct(int fd_map, t_data_mlx *mlx_data, int exit_code)
{
	t_exit	*rt;	

	rt = (t_exit *)ft_calloc(sizeof(t_exit), 1);
	if (!rt)
		return (NULL);
	rt->fd_map = fd_map;
	rt->mlx_data = mlx_data;
	rt->exit_code = exit_code;
	return (rt);
}

/*
 * Exit the game after apropriate free
 */
int	ft_exit_game(t_exit *exit_struct)
{
	int	exit_code;

	if (!exit_struct)
		exit(1);
	if (exit_struct->mlx_data)
		ft_close_mlx_data(exit_struct->mlx_data);
	close(exit_struct->fd_map);
	exit_code = exit_struct->exit_code;
	free(exit_struct);
	exit(exit_code);
}

/*
 * Initiate game
 */
void	ft_start_game(int fd_map)
{
	t_data_mlx	*mlx_data;
	t_exit		*exit_struct;

	mlx_data = ft_create_mlx_data(WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	exit_struct = ft_init_exit_struct(fd_map, mlx_data, 0);
	mlx_hook(mlx_data->mlx_win, 17, 0L, ft_exit_game, exit_struct);
	mlx_loop(mlx_data->mlx);
	ft_exit_game(exit_struct);
}



/*
 * TABlE OF img_array[x];
 * 0 = ocean (do nothing)
 * 1 = '1' (rock)
 * 2 = 'P' (dolphin)
 * 3 = 'E' (pannel)
 * 4 = 'C' (star)
int	ft_charmap_to_array_index(char charmap)
{
	if (charmap == '1')
		return (1);
	if (charmap == 'P')
		return (2);
	if (charmap == 'E')
		return (3)
	if (charmap == 'C')
		return (4);
	return (-1);
}


	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
		mlx_data->img_array[i]->img, posx, posy);
 */

void	ft_init_scene()
{
	
}
