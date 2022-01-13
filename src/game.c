/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:22:21 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/13 17:20:45 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define SPRITE_PX_DIM 50

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
 * read map
 * put image at there right position
 */
void	ft_init_scene(t_global *mlx_global)
{
	char	**array;
	int	i;
	int	y;
	// Pose background
	int *img_width = mlx_global->mlx_data->img_array[0]->img_width;
	*img_width = 56;
	mlx_put_image_to_window(
		mlx_global->mlx_data->mlx, mlx_global->mlx_data->mlx_win,
		mlx_global->mlx_data->img_array[0]->img, 0, 0);
	array = mlx_global->fd_content;
	i = 0;
	while (array[i])
	{
		y = 0;
		while (array[i][y])
		{
			if (array[i][y] == '1')
				mlx_put_image_to_window(
						mlx_global->mlx_data->mlx, mlx_global->mlx_data->mlx_win,
						mlx_global->mlx_data->img_array[1]->img, y * SPRITE_PX_DIM, i * SPRITE_PX_DIM);
			if (array[i][y] == 'P')
				mlx_put_image_to_window(
						mlx_global->mlx_data->mlx, mlx_global->mlx_data->mlx_win,
						mlx_global->mlx_data->img_array[2]->img, y * SPRITE_PX_DIM, i * SPRITE_PX_DIM);
			if (array[i][y] == 'E')
				mlx_put_image_to_window(
						mlx_global->mlx_data->mlx, mlx_global->mlx_data->mlx_win,
						mlx_global->mlx_data->img_array[3]->img, y * SPRITE_PX_DIM, i * SPRITE_PX_DIM);
			if (array[i][y] == 'C')
				mlx_put_image_to_window(
						mlx_global->mlx_data->mlx, mlx_global->mlx_data->mlx_win,
						mlx_global->mlx_data->img_array[4]->img, y * SPRITE_PX_DIM, i * SPRITE_PX_DIM);
			y++;
		}
		i++;
	}
}

/*
 * Initiate game
 */
void	ft_start_game(char	**fd_content)
{
	t_data_mlx		*mlx_data;
	t_global		*mlx_global;

	/* We use asset of 50*50px dimensions
	 * Thus the following variable adapt the window dimensions to the map dimensions
	 */
	int win_width = ft_count_colums(fd_content) * SPRITE_PX_DIM;
	int win_height = ft_count_rows(fd_content) * SPRITE_PX_DIM;

	mlx_data = ft_create_mlx_data(win_width, win_height, "so_long");
	mlx_global = ft_init_global_struct(fd_content, mlx_data, 0);
	ft_charge_all_img(mlx_data);
	ft_init_scene(mlx_global);
	mlx_hook(mlx_data->mlx_win, 17, 0L, ft_exit_game, mlx_global);
	mlx_loop(mlx_data->mlx);
	ft_exit_game(mlx_global);
}

/*
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
		mlx_data->img_array[i]->img, posx, posy);
 */
