/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:41:24 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/07 12:48:35 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd_map;
	int	correct;

	correct = 0;
	if (argc != 2)
	{
		printf("No map given as input.\n");
		return (1);
	}
	fd_map = open(argv[1], O_RDONLY);
	if (fd_map == -1)
		printf("Error, Can't open map or file doesn't exist\n");
	else
		correct = ft_is_map_correct(fd_map);
	if (correct)
		printf("Map is correct\n");
	close(fd_map);
	return (0);
}
