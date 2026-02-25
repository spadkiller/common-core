/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:55:47 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/24 13:35:40 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

t_gnl	*new_node(int fd)
{
	t_gnl	*new_n;

	new_n = malloc(sizeof(t_gnl));
	if (!new_n)
		return (NULL);
	new_n->fd = fd;
	new_n->buffer = NULL;
	new_n->next = NULL;
	return (new_n);
}

t_gnl	*search_fd(t_gnl **stock, int fd)
{
	t_gnl	*current;
	t_gnl	*new;

	if (!stock)
		return (NULL);
	current = *stock;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	new = new_node(fd);
	if (!new)
		return (NULL);
	new->next = *stock;
	*stock = new;
	return (new);
}

void	free_node(t_gnl **stock, int fd)
{
	t_gnl	*current;
	t_gnl	*prev;

	if (!stock || !*stock)
		return ;
	current = *stock;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*stock = current->next;
			free(current->buffer);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
