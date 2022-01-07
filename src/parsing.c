/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:39:57 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/07 16:18:32 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
 * if error is found: return 1 and print message.
 * 0 if not
 */
int	ft_scan_map_and_print_error(char **tab_line)
{
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
		return (0);
	return (1);
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
	rt = !ft_scan_map_and_print_error(tab_line);
	ft_free_array(tab_line);
	return (rt);
}
