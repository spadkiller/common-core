/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:49:43 by gujarry           #+#    #+#             */
/*   Updated: 2025/12/02 14:58:05 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long int	i;
	int			count;

	i = n;
	count = 0;
	if (i < 0)
	{
		count += ft_putchar('-');
		i = -i;
	}
	if (i >= 10)
		count += ft_putnbr(i / 10);
	count += ft_putchar(i % 10 + '0');
	return (count);
}
