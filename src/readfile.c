/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:20:03 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/13 10:54:27 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define BUFFER_SIZE 1

char	*ft_fd_to_str(int fd)
{
	char	*str;
	char	*tmp;
	char	*buf;
	int		rd;

	rd = 0;
	str = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str || !buf)
		return (NULL);
	rd = read(fd, buf, BUFFER_SIZE);
	while (rd > 0)
	{
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
		free(buf);
		buf = NULL;
		buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		rd = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (str);
}

void	ft_free_array(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*
 * Count the number of column inside a fd.
 */
int	ft_count_colums(int fd_map)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_fd_to_str(fd_map);
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	free(str);
	return (i);
}

/*
 * Count the number of rows inside a fd.
 */
int	ft_count_rows(int fd_map)
{
	int		i;
	int		row;
	char	*str;

	i = 0;
	row = 0;
	str = ft_fd_to_str(fd_map);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			row++;
		i++;
	}
	free(str);
	return (row);
}

char	**ft_fd_to_split_lines(int fd_map)
{
	char	*str;
	char	**fd_content;

	str = ft_fd_to_str(fd_map);
	fd_content = ft_split(str, '\n');
	free(str);
	return (fd_content);
}
