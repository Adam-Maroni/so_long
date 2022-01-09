/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myMlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:25:36 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/09 13:00:09 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data_img *data_img, int x, int y, int color)
{
	char	*dst;

	dst = data_img->addr
		+ (y * data_img->line_length + x * (data_img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_data_mlx	*ft_create_mlx_data(int width, int height, char *title)
{
	t_data_mlx	*rt;

	rt = (t_data_mlx *)ft_calloc(sizeof(t_data_mlx), 1);
	rt->mlx = mlx_init();
	rt->mlx_win = mlx_new_window(rt->mlx, width, height, title);
	rt->img = (t_data_img *)ft_calloc(sizeof(t_data_img), 1);
	rt->img->img = mlx_new_image(rt->mlx, width, height);
	rt->img->addr = mlx_get_data_addr(rt->img->img, &(rt->img->bits_per_pixel),
			&(rt->img->line_length), &(rt->img->endian));
	return (rt);
}

/*
 * CLOSE AND FREE MLX
 */
void	ft_close_mlx_data(t_data_mlx *mlx_data)
{
	if (!mlx_data)
		return ;
	if (mlx_data->img)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->img->img);
		free(mlx_data->img);
	}
	if (mlx_data->mlx_win)
		mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
	if (mlx_data->mlx)
	{
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
	}
	mlx_data->img = NULL;
	mlx_data->mlx_win = NULL;
	mlx_data->mlx = NULL;
	free(mlx_data);
}

void	ft_display_image(t_data_mlx *mlx_data)
{
	mlx_put_image_to_window(mlx_data->mlx,
		mlx_data->mlx_win, mlx_data->img->img, 0, 0);
	mlx_loop(mlx_data->mlx);
}
