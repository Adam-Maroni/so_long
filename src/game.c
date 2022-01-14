/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:22:21 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/14 15:52:41 by amaroni          ###   ########.fr       */
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
 * player_x =  current player x pos
 * player_y =  current player y pos
 */
void	ft_player_move_up(t_global *mlx_global)
{
	char	**array;
	int	x;
	int	y;

	if (!mlx_global || !mlx_global->fd_content || !mlx_global->mlx_data)
		return ;
	//Change the pos inside fd_content;
	array = mlx_global->fd_content;
	x = 0;
	while (array[x])
	{
		y = 0;
		while (array[x][y])
		{
			if (array[x][y] == 'P' && x > 0)
			{
				array[x][y] = '0';
				array[x - 1][y] = 'P';
			}
			y++;
		}
		x++;
	}
	ft_close_all_img(mlx_global->mlx_data);
	ft_charge_all_img(mlx_global->mlx_data);
	ft_generate_scene(mlx_global);
}

int	key_hook(int key_code, t_global *mlx_global)
{
	if (key_code == (char) 'w')
		ft_player_move_up(mlx_global);
	else if (key_code == (char) 'a')
		;//GO LEFT
	else if (key_code == (char) 's')
		;//GO DOWN
	else if (key_code == (char) 'd')
		;//GO RIGHT
	return (0);
}

/*
 * The function to be call when hook
 */
void	ft_event_handler(t_global *mlx_global)
{
	void	*win_ptr;

	if (!mlx_global)
		return ;
	win_ptr = mlx_global->mlx_data->mlx_win;
	if (!win_ptr)
		return ;
	mlx_key_hook(mlx_global->mlx_data->mlx_win, key_hook, mlx_global);
	mlx_hook(mlx_global->mlx_data->mlx_win, 17, 0L, ft_exit_game, mlx_global);
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
	ft_charge_all_img(mlx_data);
	ft_generate_scene(mlx_global);
	ft_event_handler(mlx_global);
	mlx_loop(mlx_data->mlx);
	ft_exit_game(mlx_global);
}
