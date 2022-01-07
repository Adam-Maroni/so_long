/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:28:22 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/07 12:36:01 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd_map;

	if (argc != 2)
	{
		printf("No map given as input.\n");
		return (1);
	}
	fd_map = open(argv[1], O_RDONLY);
	if (fd_map == -1)
		printf("Error, Can't open map or file doesn't exist\n");
	else
	{
		char *str = ft_fd_to_str(fd_map);
	}
	close(fd_map);
	return (0);
}
