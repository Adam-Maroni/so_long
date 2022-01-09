/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:28:22 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/09 12:49:48 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data_mlx *mlx_data;

	mlx_data = NULL;
	mlx_data = ft_create_mlx_data(100, 100, "so_long");
	//ft_display_image(mlx_data);	
	//mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	//mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
	//mlx_destroy_display(mlx_data->mlx);
	ft_close_mlx_data(mlx_data);
	return (0);
}
