/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:16:06 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/17 08:02:05 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Count the number of column inside a fd.
 */
int	ft_count_colums(char **fd_content)
{
	int		i;

	i = 0;
	if (!fd_content)
		return (0);
	return (ft_strlen(fd_content[0]));
}

/*
 * Count the number of rows inside a fd.
 */
int	ft_count_rows(char **fd_content)
{
	int		i;

	i = 0;
	if (!fd_content)
		return (0);
	while (fd_content[i])
		i++;
	return (i);
}

/*
 * Count the number of occurence of character c
 * among map
 */
int	ft_count_char(char **fd_content, char c)
{
	int	x;
	int	y;
	int	rt;

	if (!fd_content)
		return (0);
	rt = 0;
	x = 0;
	while (fd_content[x])
	{
		y = 0;
		while (fd_content[x][y])
		{
			if (fd_content[x][y] == c)
				rt++;
			y++;
		}
		x++;
	}
	return (rt);
}
