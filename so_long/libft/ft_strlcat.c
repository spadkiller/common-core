/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:49:18 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/13 13:41:29 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t s)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = 0;
	src_len = ft_strlen((char *)src);
	while (dest[dest_len] && dest_len < s)
		dest_len++;
	if (dest_len >= s)
		return (s + src_len);
	while (src[i] && dest_len + i + 1 < s)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest_len + src_len);
}
/*int	main(void)
{
	char dest[SIZE] = {'a','a','a','a','a','a','a','a','a','a','a', '\0'}
	char dest1[SIZE] = {'a','a','a','a','a','a','a','a','a','a','a', '\0'}
	char src[] = " les";

	printf("ft_strlcat : %d , %s\n", ft_strlcat(dest, src, 11)dest);
	printf("strlcat : %d , %s\n", strlcat(dest, src, 11)dest1);
	return (0);
}*/
