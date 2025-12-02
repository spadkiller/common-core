/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:03:38 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/14 12:49:02 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	str;

	str = malloc(11 * sizeof(char)); // créer une zone mémoire de 10 chars
		+ '\0'
	if (!str)
		return (1);
	ft_memset(str, 'A', 10); // Remplit avec 'A'
	str[10] = '\0';          // On ajoute un \0 pour l'affichage
	printf("%s\n", str);     // Doit afficher AAAAAAAAAA
	free(str);
	return (0);
}
	*/
