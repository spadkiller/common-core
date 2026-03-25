/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:37:55 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/13 09:54:04 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*Function Name         ft_lstsize
Prototype               int ft_lstsize(t_list *lst);
Files to Submit         -
Parameters              lst: The beginning of the list.
Return Value            The length of the list
External Function       None
Description             Counts the number of nodes in the list*/