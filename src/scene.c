/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:47:48 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/15 18:26:51 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Return the pixel address of img
 * at position(x,y)
 */
void	*ft_get_pixel(t_data_img *img, int x, int y)
{
	void	*pixel;

	if (!img || !img->addr)
		return (NULL);
	pixel = img->addr
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (pixel);
}

/*
 * If img_pixel is transparent,
 * put background pixel Instead
 */
void	ft_handle_transparent_pixel(
		void *bg_pixel, void *sprite_pixel, unsigned int transparent_color_code)
{
	if (!bg_pixel || !sprite_pixel)
		return ;
	if (*(unsigned int *)sprite_pixel == transparent_color_code)
		*(unsigned int *)sprite_pixel = *(unsigned int *)bg_pixel;
}

/*
 * Handle transparent pixel and then mlx_put_image
 * x = x position of image
 * y = y position of image
 * relative_x = x coordinates in sprite plan
 * relative_y = y coordinates in sprite plan
 * offset_y = buffer for y
 */
void	ft_put_img(t_global *mlx_global, t_data_img *sprite, int x, int y)
{
	int			relative_x;
	int			relative_y;
	int			offset_y;
	t_data_img	*bg;

	relative_x = 0;
	bg = mlx_global->mlx_data->img_array[0];
	while (relative_x < SPRITE_PX_DIM)
	{
		relative_y = 0;
		offset_y = y;
		while (relative_y < SPRITE_PX_DIM)
		{
			ft_handle_transparent_pixel(
				ft_get_pixel(bg, x + relative_x, offset_y),
				ft_get_pixel(sprite, relative_x, relative_y),
				TRANSPARENT_COLOR_CODE);
			offset_y++;
			relative_y++;
		}
		relative_x++;
	}
	mlx_put_image_to_window(mlx_global->mlx_data->mlx,
		mlx_global->mlx_data->mlx_win, sprite->img, y, x);
}

/*
 * char map_element: the character from the map
 * int x: x coordinate of image
 * int y: y coordinate of image
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
		ft_put_img(mlx_global, mlx_global->mlx_data->img_array[2], x * SPRITE_PX_DIM, y * SPRITE_PX_DIM);
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
 * Build the game's initial scene
 */
void	ft_generate_scene(t_global *mlx_global)
{
	char	**array;
	int		x;
	int		y;

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
