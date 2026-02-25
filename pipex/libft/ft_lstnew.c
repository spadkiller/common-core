/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:41:19 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/13 09:53:26 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*Function Name            ft_lstnew
Prototype                  t_list *ft_lstnew(void *content);
Files to Submit            -
Parameters content:        The content to store in the new node.
Return Value            A pointer to the new node
External Function       malloc
Description             Allocates memory (using malloc(3)) and returns
						a new node. The ’content’ member variable is
						initialized with the given parameter ’content’.
						The variable ’next’ is initialized to NULL.*/