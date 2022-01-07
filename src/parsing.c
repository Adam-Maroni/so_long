/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:39:57 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/07 13:36:11 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Should return 1 if map is correct and 0 if not.
 * check for each line that first and last character is a 1.
 * check each first and last element of line is a 1.
 * Check first and last line are same length.
 * Check each element of first and last line is a 1.
*/
int	ft_is_closed_rectangle(char	**line_array)
{
	char	*first_line;
	char	*line;
	int		i;

	i = 0;
	while (line_array[i])
	{
		line = line_array[i];
		if (i == 0)
			first_line = line_array[i];
		if (ft_strlen(line) <= 0 || line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			return (0);
		i++;
	}
	if (i <= 1 || ft_strlen(line) <= 1
		|| ft_strlen(line) != ft_strlen(first_line))
		return (0);
	i = 0;
	while (first_line[i] && line[i])
		if (first_line[i] != '1' || line[i] != '1')
			return (0);
	else
		i++;
	return (1);
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

/* Should return 1 if map is correct and 0 if not */
int	ft_is_map_correct(int fd_map)
{
	char	**tab_line;
	int		rt;
	char	*fd_content;

	tab_line = NULL;
	fd_content = ft_fd_to_str(fd_map);
	if (fd_content)
	{
		tab_line = ft_split(fd_content, '\n');
		free(fd_content);
	}
	rt = 0;
	if (!tab_line || !tab_line[0])
		printf("Error, Map is empty\n");
	else if (!ft_is_closed_rectangle(tab_line))
		printf("Error, Map is not a closed rectangle.\n");
	else
		rt = 1;
	ft_free_array(tab_line);
	return (rt);
}
