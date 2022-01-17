/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:22:21 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/17 13:40:15 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_global	*ft_init_global_struct(
		char **fd_content, t_data_mlx *mlx_data, int exit_code)
{
	t_global	*rt;	

	rt = (t_global *)ft_calloc(sizeof(t_global), 1);
	if (!rt)
		return (NULL);
	rt->fd_content = fd_content;
	rt->mlx_data = mlx_data;
	rt->exit_code = exit_code;
	return (rt);
}

/*
 * Exit the game after apropriate free
 */
int	ft_exit_game(t_global *mlx_global)
{
	int	exit_code;

	if (!mlx_global)
		exit(1);
	if (mlx_global->mlx_data)
		ft_close_mlx_data(mlx_global->mlx_data);
	ft_free_array(mlx_global->fd_content);
	exit_code = mlx_global->exit_code;
	free(mlx_global);
	exit(exit_code);
}

/*
 * Initiate game
 */
void	ft_start_game(char	**fd_content)
{
	t_data_mlx	*mlx_data;
	t_global	*mlx_global;
	int			win_width;
	int			win_height;

	win_width = ft_count_colums(fd_content) * SPRITE_PX_DIM;
	win_height = ft_count_rows(fd_content) * SPRITE_PX_DIM;
	mlx_data = ft_create_mlx_data(win_width, win_height, "so_long");
	mlx_global = ft_init_global_struct(fd_content, mlx_data, 0);
	ft_charge_all_img(mlx_global);
	ft_generate_scene(mlx_global);
	ft_event_handler(mlx_global);
	mlx_loop(mlx_data->mlx);
	ft_exit_game(mlx_global);
}
