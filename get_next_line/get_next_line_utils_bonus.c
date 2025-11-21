/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:55:47 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/21 16:57:28 by gujarry          ###   ########.fr       */
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
t_gnl	search_fd(t_gnl *stock,int fd)
{
    while (next != fd)
    {
        
    }
            
}
t_gnl	*new_node(int    fd)
{
	t_gnl	*new_n;
    if (!fd)
    {
	    new_n = malloc(sizeof(t_gnl));
	    if (!new_n)
		    return (NULL);
        new_n->next = new_n;
        new_n = fd;
        new_n->buffer = NULL;
    }    
}
t_gnl	add_node(void)
{
}
t_gnl	free_node(void)
{
}
