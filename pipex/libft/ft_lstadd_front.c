/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:23:14 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/13 13:06:30 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
//*lst = pointeur de tete , **lst =  pointeur contenu

/*Function Name         ft_lstadd_front
Prototype               void ft_lstadd_front(t_list **lst, t_list *new);
Files to Submit          -
Parameters              lst: The address of a pointer to the first node of
						a list.
						new: The address of a pointer to the node to be added.
Return Value            None
External                Function None
Description             Adds the node ’new’ at the beginning of the list.*/