/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:55:40 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/14 12:50:32 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *strg1, char const *strg2)
{
	size_t	len;
	char	*dest;

	if (!strg1 || !strg2)
		return (NULL);
	len = ft_strlen(strg1) + ft_strlen(strg2);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	ft_strcat(dest, strg1);
	ft_strcat(dest, strg2);
	return (dest);
}
/*#include <stdio.h>

int	main(void)
{
	char *s = ft_strjoin("Hello, ", "World!");
	printf("%s\n", s);
	free(s);
	return (0);
}*/