/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:25:36 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/13 09:18:15 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define MAX_IMAGES 10

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
 * As well as an array of MAX_IMAGES - 1 images.
 */
t_data_mlx	*ft_create_mlx_data(int width, int height, char *title)
{
	t_data_mlx	*rt;
	int			i;

	rt = (t_data_mlx *)ft_calloc(sizeof(t_data_mlx), 1);
	rt->mlx = mlx_init();
	rt->mlx_win = mlx_new_window(rt->mlx, width, height, title);
	i = -1;
	while (++i < MAX_IMAGES)
		rt->img_array[i] = NULL;
	return (rt);
}

/*
 * If xpm_filepath == NULL 
 * then mlx_new_image
 * else
 * mlx_xpm_file_to_image
 */
t_data_img	*ft_create_new_image(void *mlx, char *xpm_filepath)
{
	t_data_img	*new_img;

	if (!mlx)
		return (NULL);
	new_img = (t_data_img *)ft_calloc(sizeof(t_data_img), 1);
	if (!new_img)
		return (NULL);
	new_img->img_height = (int *)ft_calloc(sizeof(int), 1);
	new_img->img_width = (int *)ft_calloc(sizeof(int), 1);
	if (!new_img->img_width || !new_img->img_height)
	{
		ft_close_mlx_img(mlx, new_img);
		return (NULL);
	}
	if (!xpm_filepath)
		new_img->img = mlx_new_image(mlx,
				*new_img->img_width, *new_img->img_height);
	else
		new_img->img = mlx_xpm_file_to_image(mlx, xpm_filepath,
				new_img->img_width, new_img->img_height);
	new_img->addr = mlx_get_data_addr(new_img->img, &(new_img->bits_per_pixel),
			&(new_img->line_length), &(new_img->endian));
	return (new_img);
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

void	ft_charge_all_img(t_data_mlx *mlx_data)
{
	ft_add_img(mlx_data,
		ft_create_new_image(mlx_data->mlx, "./assets/ocean.xpm"), 0);
	ft_add_img(mlx_data,
		ft_create_new_image(mlx_data->mlx, "./assets/rock.xpm"), 1);
	ft_add_img(mlx_data,
		ft_create_new_image(mlx_data->mlx, "./assets/dolphin.xpm"), 2);
	ft_add_img(mlx_data,
		ft_create_new_image(mlx_data->mlx, "./assets/pannel.xpm"), 3);
	ft_add_img(mlx_data,
		ft_create_new_image(mlx_data->mlx, "./assets/starfish.xpm"), 4);
}
