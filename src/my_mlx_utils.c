/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:25:36 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/12 15:24:50 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define	MAX_IMAGES 10

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
 */
void	ft_add_and_display_img(t_data_mlx *mlx_data, t_data_img *new_img,
		int posx, int posy)
{
	int	i;

	if (!mlx_data || !new_img)
		return ;
	i = 0;
	while ((t_data_img *)mlx_data->img_array[i])
		i++;
	mlx_data->img_array[i] = new_img;
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
		mlx_data->img_array[i]->img, posx, posy);
}
