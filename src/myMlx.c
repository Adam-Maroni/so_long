/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myMlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:25:36 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/08 15:55:35 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data_img *data_img, int x, int y, int color)
{
	char	*dst;

	dst = data_img->addr + (y * data_img->line_length + x * (data_img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_data_mlx	*ft_create_mlx_data(int width, int height, char *title)
{
	t_data_mlx	*rt;
	t_data_img	*img;	

	rt = (t_data_mlx *)ft_calloc(sizeof(t_data_mlx), 1);
	rt->mlx = mlx_init();
	//Create window
	rt->mlx_win = mlx_new_window(rt->mlx, width, height, title);
	//create image
	rt->img = (t_data_img *)ft_calloc(sizeof(t_data_img), 1);
	img = rt->img;
	img->img = mlx_new_image(rt->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	return (rt);
}

void	ft_free_img_data(t_data_img *mlx_img)
{
	if (!mlx_img)
		return ;
	if (mlx_img->img)
		free(mlx_img->img);
	if (mlx_img->addr)
		;//free(mlx_img->addr);
	mlx_img->img = NULL;
	mlx_img->addr = NULL;
	free(mlx_img);
	mlx_img = NULL;
}

void	ft_free_mlx_data(t_data_mlx *mlx_data)
{
	if (!mlx_data)
		return ;
	if (mlx_data->mlx)
		free(mlx_data->mlx);
	if (mlx_data->mlx_win)
		free(mlx_data->mlx_win);
	if (mlx_data->img)
		ft_free_img_data(mlx_data->img);
	mlx_data->mlx = NULL;
	mlx_data->mlx_win = NULL;
	mlx_data->img = NULL;
	free(mlx_data);
	mlx_data = NULL;
}

void	ft_display_image(t_data_mlx *mlx_data)
{
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img->img, 0, 0);
	mlx_loop(mlx_data->mlx);
}
