/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:39:57 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/07 14:49:46 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Check if the given character is acceptable.
 */
int	ft_is_char_valid(char c)
{
	if (c == '0'
		|| c == '1'
		|| c == 'C'
		|| c == 'E'
		|| c == 'P'
		|| c == '\n')
		return (1);
	return (0);
}

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
		if (ft_strlen(line) <= 0 || line[0] != '1'
			|| line[ft_strlen(line) - 1] != '1')
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

/*
 * Should return 1 if c is found at least Once
 * in at least once line of array.
 */
int	ft_is_character_among_array(char **line_array, int c)
{
	int		i;
	char	*current_line;

	if (!line_array)
		return (0);
	i = 0;
	while (line_array[i])
	{
		current_line = line_array[i];
		if (ft_strchr(current_line, c))
			return (1);
		i++;
	}
	return (0);
}

/*
 *	1 if there are
 *	0 if there None
 */
int	ft_is_there_nonvalid_char(char **line_array)
{
	int		i;
	int		y;
	char	*current_line;

	if (!line_array)
		return (0);
	i = 0;
	while (line_array[i])
	{
		y = 0;
		current_line = line_array[i];
		while (current_line[y])
			if (!ft_is_char_valid(current_line[y]))
				return (1);
		else
			y++;
		i++;
	}
	return (0);
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
	else if (!ft_is_character_among_array(tab_line, (int) 'E'))
		printf("Error, exit missing.\n");
	else if (!ft_is_character_among_array(tab_line, (int) 'P'))
		printf("Error, starting position missing.\n");
	else if (!ft_is_character_among_array(tab_line, (int) 'C'))
		printf("Error, collectible missing.\n");
	else if (ft_is_there_nonvalid_char(tab_line))
		printf("Error, characters non valid.\n");
	else
		rt = 1;
	ft_free_array(tab_line);
	return (rt);
}
