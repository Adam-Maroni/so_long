/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:41:24 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/13 10:54:14 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd_map;
	char	**fd_content;

	if (argc != 2)
	{
		printf("No map given as input.\n");
		return (1);
	}
	fd_map = open(argv[1], O_RDONLY);
	if (fd_map == -1)
	{
		printf("Error, Can't open map or file doesn't exist\n");
		close (fd_map);
		return (1);
	}
	fd_content = ft_fd_to_split_lines(fd_map);
	close (fd_map);
	if (ft_is_map_correct(fd_content))
		ft_start_game(fd_content);
	return (0);
}
