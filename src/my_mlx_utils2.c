/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:25:36 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/14 15:49:55 by amaroni          ###   ########.fr       */
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
	int i;

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
 * DESTROY AND FREE MLX DATA
 */
void	ft_close_mlx_data(t_data_mlx *mlx_data)
{
	if (!mlx_data)
		return ;
	ft_close_all_img(mlx_data);
	if (mlx_data->mlx_win)
		mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
	if (mlx_data->mlx)
	{
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
	}
	mlx_data->mlx_win = NULL;
	mlx_data->mlx = NULL;
	free(mlx_data);
}
