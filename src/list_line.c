/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:02:50 by amaroni           #+#    #+#             */
/*   Updated: 2022/01/07 12:48:22 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_fd_to_line_list(int fd)
{
	char	*line;
	t_list	*line_list;

	line = NULL;
	line_list = NULL;
	if (fd < 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstadd_back(&line_list, ft_lstnew(line));
		line = NULL;
	}
	free(line);
	return (line_list);
}

void	ft_lstclear_line_list(t_list **lst)
{
	t_list	*current;
	t_list	*previous;

	previous = (*lst)->next;
	while (previous)
	{
		current = previous->next;
		free(previous->content);
		free(previous);
		previous = current;
	}
	if ((*lst)->content)
	{
		free((*lst)->content);
		(*lst)->content = NULL;
	}
	if (*lst)
		free(*lst);
	(*lst) = NULL;
}
