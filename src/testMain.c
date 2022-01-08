/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:28:22 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/08 15:51:59 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data_mlx *mlx_data;

	mlx_data = NULL;
	mlx_data = ft_create_mlx_data(1920, 1080, "so_long");
	//ft_display_image(mlx_data);	
	ft_free_mlx_data(mlx_data);
	return (0);
}
