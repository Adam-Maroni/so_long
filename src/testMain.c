/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:28:22 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/12 08:39:01 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int img_width;
	int img_height;
	int dolphin_width;
	int dolphin_height;

	char *relative_path = "./assets/ocean.xpm";
	t_data_img	img;
	t_data_img	dolphin;

	int window_width = 1531;
	int window_height = 980;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, window_width, window_height, "Hello world!");
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	dolphin.img = mlx_xpm_file_to_image(mlx, "./assets/dolphin.xpm", &dolphin_width, &dolphin_height);
	dolphin.addr = mlx_get_data_addr(dolphin.img, &dolphin.bits_per_pixel, &dolphin.line_length, &dolphin.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//mlx_put_image_to_window(mlx, mlx_win, dolphin.img, 960, 540);
	mlx_loop(mlx);
}
