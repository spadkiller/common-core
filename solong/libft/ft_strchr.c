/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:27:42 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/13 14:02:54 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	size_t			i;
	unsigned char	c;

	i = 0;
	c = (unsigned char)searchedChar;
	while (i <= ft_strlen(string))
	{
		if ((unsigned char)string[i] == c)
			return ((char *)&string[i]);
		i++;
	}
	return (NULL);
}
