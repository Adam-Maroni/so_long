/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:47:48 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/14 08:47:55 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Giventhe map element
 * add the corresponding image to the scene
 */
void	ft_map_to_scene(t_global *mlx_global, char map_element, int x, int y)
{
	if (map_element == '1')
		mlx_put_image_to_window(
			mlx_global->mlx_data->mlx, mlx_global->mlx_data->mlx_win,
			mlx_global->mlx_data->img_array[1]->img,
			y * SPRITE_PX_DIM, x * SPRITE_PX_DIM);
	if (map_element == 'P')
		mlx_put_image_to_window(
			mlx_global->mlx_data->mlx, mlx_global->mlx_data->mlx_win,
			mlx_global->mlx_data->img_array[2]->img,
			y * SPRITE_PX_DIM, x * SPRITE_PX_DIM);
	if (map_element == 'E')
		mlx_put_image_to_window(
			mlx_global->mlx_data->mlx, mlx_global->mlx_data->mlx_win,
			mlx_global->mlx_data->img_array[3]->img,
			y * SPRITE_PX_DIM, x * SPRITE_PX_DIM);
	if (map_element == 'C')
		mlx_put_image_to_window(
			mlx_global->mlx_data->mlx, mlx_global->mlx_data->mlx_win,
			mlx_global->mlx_data->img_array[4]->img,
			y * SPRITE_PX_DIM, x * SPRITE_PX_DIM);
}

/*
 * read map
 * put image at there right position
 */
void	ft_init_scene(t_global *mlx_global)
{
	char	**array;
	int		x;
	int		y;
	// Pose background
	mlx_put_image_to_window(
		mlx_global->mlx_data->mlx, mlx_global->mlx_data->mlx_win,
		mlx_global->mlx_data->img_array[0]->img, 0, 0);
	array = mlx_global->fd_content;
	x = 0;
	while (array[x])
	{
		y = 0;
		while (array[x][y])
		{
			ft_map_to_scene(mlx_global, array[x][y], x, y);
			y++;
		}
		x++;
	}
}
