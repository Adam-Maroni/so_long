/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:25:36 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/17 13:54:09 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * DESTROY AND FREE MLX IMG
 */
void	ft_close_mlx_img(void *mlx, t_data_img *img)
{
	if (!img)
		return ;
	mlx_destroy_image(mlx, img->img);
	if (img->img_width)
		free(img->img_width);
	if (img->img_height)
		free(img->img_height);
	img->img = NULL;
	img->addr = NULL;
	img->img_width = NULL;
	img->img_height = NULL;
	free(img);
}

/*
 * Close every single image of mlx_data.
 */
void	ft_close_all_img(t_data_mlx *mlx_data)
{
	int	i;

	i = 0;
	if (!mlx_data)
		return ;
	while (mlx_data->img_array[i])
	{
		ft_close_mlx_img(mlx_data->mlx, mlx_data->img_array[i]);
		mlx_data->img_array[i] = NULL;
		i++;
	}
}

/*
 * Add an image to a display
 * index: where the new img should be save.
 * TABlE OF img_array[index];
 * 0 = ocean (do nothing)
 * 1 = '1' (rock)
 * 2 = 'P' (dolphin)
 * 3 = 'E' (pannel)
 * 4 = 'C' (star)
 */
void	ft_add_img(t_data_mlx *mlx_data, t_data_img *new_img, int index)
{
	if (!mlx_data || !new_img)
		return ;
	mlx_data->img_array[index] = new_img;
}

/*
 * Try to create img and add it to mlx_data
 * if it fails, exit game
 */
void	ft_handle_img(t_global *mlx_global, char *img_path, int img_array_id)
{
	t_data_img	*img;

	mlx_global->exit_code = 1;
	if (access(img_path, F_OK) != 0)
	{
		printf("Error, problem with image :%s\n", img_path);
		ft_exit_game(mlx_global);
	}
	img = ft_create_new_image(mlx_global->mlx_data->mlx, img_path);
	if (!img)
	{
		printf("Error, problem with image :%s\n", img_path);
		ft_exit_game(mlx_global);
	}
	ft_add_img(mlx_global->mlx_data, img, img_array_id);
	mlx_global->exit_code = 0;
}

void	ft_charge_all_img(t_global *mlx_global)
{
	ft_handle_img(mlx_global, "./assets/ocean.xpm", 0);
	ft_handle_img(mlx_global, "./assets/rock.xpm", 1);
	ft_handle_img(mlx_global, "./assets/dolphin.xpm", 2);
	ft_handle_img(mlx_global, "./assets/pannel.xpm", 3);
	ft_handle_img(mlx_global, "./assets/starfish.xpm", 4);
}
