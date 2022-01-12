/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:22:21 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/12 14:37:17 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	mlx_data = ft_create_mlx_data(1531, 980, "so_long");
	exit_struct = ft_init_exit_struct(fd_map, mlx_data, 0);
	ft_add_and_display_img(mlx_data,
		ft_create_new_image(mlx_data->mlx, "./assets/ocean.xpm"),
		0, 0);
	mlx_hook(mlx_data->mlx_win, 17, 0L, ft_exit_game, exit_struct);
	mlx_loop(mlx_data->mlx);
	ft_exit_game(exit_struct);
}