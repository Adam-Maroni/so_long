/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myMlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:25:36 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/12 10:41:40 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Generic function to draw pixel
 * on images
 */
void	my_mlx_pixel_put(t_data_img *data_img, int x, int y, int color)
{
	char	*dst;

	dst = data_img->addr
		+ (y * data_img->line_length + x * (data_img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
 * Create the display and window for the game.
 * As well as an array of 9 images.
 */
t_data_mlx	*ft_create_mlx_data(int width, int height, char *title)
{
	t_data_mlx	*rt;
	int			i;

	rt = (t_data_mlx *)ft_calloc(sizeof(t_data_mlx), 1);
	rt->mlx = mlx_init();
	rt->mlx_win = mlx_new_window(rt->mlx, width, height, title);
	i = -1;
	while (++i < 10)
		rt->img_array[i] = NULL;
	return (rt);
}

t_data_img	*ft_create_new_image(void *mlx, int width, int height)
{
	t_data_img	*new_img;

	if (!mlx || width <= 0 || height <= 0)
		return (NULL);
	new_img = (t_data_img *)ft_calloc(sizeof(t_data_img), 1);
	new_img->img = mlx_new_image(mlx, width, height);
	new_img->addr = mlx_get_data_addr(new_img->img, &(new_img->bits_per_pixel),
			&(new_img->line_length), &(new_img->endian));
	return (new_img);
}

/*
 * Add an image to a display
 */
void	ft_add_image(t_data_mlx *mlx_data, t_data_img *new_img)
{
	int	i;

	if (!mlx_data || !new_img)
		return ;
	i = 0;
	while ((t_data_img *)mlx_data->img_array[i])
		i++;
	mlx_data->img_array[i] = new_img;
}

/*
 * CLOSE AND FREE MLX
 */
void	ft_close_mlx_data(t_data_mlx *mlx_data)
{
	int	i;

	i = 0;
	if (!mlx_data)
		return ;
	while (mlx_data->img_array[i])
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_array[i]->img);
		free(mlx_data->img_array[i]);
		mlx_data->img_array[i] = NULL;
		i++;
	}
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

/*
 * Put an image to the window
 * posx and posy are the coordinate on window
 * where the origin of image should be put
 */
void	ft_display_mlx_img(t_data_mlx *mlx_data, t_data_img *img,
		int posx, int posy)
{
	mlx_put_image_to_window(mlx_data->mlx,
		mlx_data->mlx_win, img, posx, posy);
	mlx_loop(mlx_data->mlx);
}
