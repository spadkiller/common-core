/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:49:14 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/13 09:54:25 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*scan;

	i = 0;
	scan = (unsigned char *)s;
	while (i < n)
	{
		if (scan[i] == (unsigned char)c)
			return (&scan[i]);
		i++;
	}
	return (NULL);
}

/*int    main(void)
{
	int                data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	unsigned int    size = sizeof(data);
	int                *result;

	result = ft_memchr(data, 50, size);
	printf("50 is %d\n", *result);

}*/