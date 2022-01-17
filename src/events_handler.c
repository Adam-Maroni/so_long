/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:04:27 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/17 13:40:35 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * x_move = -1 or 1 or 0
 *	-1 means left , 1 means right, 0 means stay
 * y_move = -1 or 1 or 0
 *	-1 means up , 1 means down, 0 means stay
 */
void	ft_player_make_a_move(t_global *mlx_global, int x_move, int y_move)
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
			if (array[x][y] == 'P' && x > 0
					&& array[x + x_move][y + y_move] != '1')
			{
				array[x][y] = '0';
				array[x + x_move][y + y_move] = 'P';
				return ;
			}
			y++;
		}
		x++;
	}
}

int	ft_key_hook(int key_code, t_global *mlx_global)
{
	static int	move_count = 0;
	int			exit_count;

	exit_count = ft_count_char(mlx_global->fd_content, 'E');
	if (key_code == (char) 'w')
		ft_player_make_a_move(mlx_global, -1, 0);
	else if (key_code == (char) 'a')
		ft_player_make_a_move(mlx_global, 0, -1);
	else if (key_code == (char) 's')
		ft_player_make_a_move(mlx_global, +1, 0);
	else if (key_code == (char) 'd')
		ft_player_make_a_move(mlx_global, 0, 1);
	else if (key_code == 65307)
		ft_exit_game(mlx_global);
	else
		return (0);
	move_count++;
	printf("%d\n", move_count);
	ft_close_all_img(mlx_global->mlx_data);
	ft_charge_all_img(mlx_global);
	ft_generate_scene(mlx_global);
	if (exit_count != ft_count_char(mlx_global->fd_content, 'E'))
		ft_exit_game(mlx_global);
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
	mlx_key_hook(mlx_global->mlx_data->mlx_win, ft_key_hook, mlx_global);
	mlx_hook(mlx_global->mlx_data->mlx_win, 17, 0L, ft_exit_game, mlx_global);
}
