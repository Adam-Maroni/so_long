/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:04:27 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/14 18:30:49 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * player_x =  current player x pos
 * player_y =  current player y pos
 */
void	ft_player_move_up(t_global *mlx_global)
{
	char	**array;
	int		x;
	int		y;

	if (!mlx_global || !mlx_global->fd_content || !mlx_global->mlx_data)
		return ;
	array = mlx_global->fd_content;
	x = 0;
	while (array[x])
	{
		y = 0;
		while (array[x][y])
		{
			if (array[x][y] == 'P' && x > 0 && array[x - 1][y] != '1')
			{
				array[x][y] = '0';
				array[x - 1][y] = 'P';
				x = -1;
				break ;
			}
			y++;
		}
		if (x == -1)
			break ;
		x++;
	}
	ft_close_all_img(mlx_global->mlx_data);
	ft_charge_all_img(mlx_global->mlx_data);
	ft_generate_scene(mlx_global);
}

/*
 * player_x =  current player x pos
 * player_y =  current player y pos
 */
void	ft_player_move_down(t_global *mlx_global)
{
	char	**array;
	int		x;
	int		y;

	if (!mlx_global || !mlx_global->fd_content || !mlx_global->mlx_data)
		return ;
	array = mlx_global->fd_content;
	x = 0;
	while (array[x])
	{
		y = 0;
		while (array[x][y])
		{
			if (array[x][y] == 'P' && x > 0 && array[x + 1][y] != '1')
			{
				array[x][y] = '0';
				array[x + 1][y] = 'P';
				x = -1;
				break;
			}
			y++;
		}
		if (x == -1)
			break;
		x++;
	}
	ft_close_all_img(mlx_global->mlx_data);
	ft_charge_all_img(mlx_global->mlx_data);
	ft_generate_scene(mlx_global);
}

/*
 * player_x =  current player x pos
 * player_y =  current player y pos
 */
void	ft_player_move_left(t_global *mlx_global)
{
	char	**array;
	int		x;
	int		y;

	if (!mlx_global || !mlx_global->fd_content || !mlx_global->mlx_data)
		return ;
	array = mlx_global->fd_content;
	x = 0;
	while (array[x])
	{
		y = 0;
		while (array[x][y])
		{
			if (array[x][y] == 'P' && x > 0 && array[x][y - 1] != '1')
			{
				array[x][y] = '0';
				array[x][y - 1] = 'P';
				x = -1;
				break ;
			}
			y++;
		}
		if (x == -1)
			break ;
		x++;
	}
	ft_close_all_img(mlx_global->mlx_data);
	ft_charge_all_img(mlx_global->mlx_data);
	ft_generate_scene(mlx_global);
}

/*
 * player_x =  current player x pos
 * player_y =  current player y pos
 */
void	ft_player_move_right(t_global *mlx_global)
{
	char	**array;
	int		x;
	int		y;

	if (!mlx_global || !mlx_global->fd_content || !mlx_global->mlx_data)
		return ;
	array = mlx_global->fd_content;
	x = 0;
	while (array[x])
	{
		y = 0;
		while (array[x][y])
		{
			if (array[x][y] == 'P' && x > 0 && array[x][y + 1] != '1')
			{
				array[x][y] = '0';
				array[x][y + 1] = 'P';
				x = -1;
				break;
			}
			y++;
		}
		if (x == -1)
			break ;
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
		ft_player_move_left(mlx_global);
	else if (key_code == (char) 's')
		ft_player_move_down(mlx_global);
	else if (key_code == (char) 'd')
		ft_player_move_right(mlx_global);
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
