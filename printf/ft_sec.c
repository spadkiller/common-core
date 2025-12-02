/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:49:43 by gujarry           #+#    #+#             */
/*   Updated: 2025/12/02 11:53:37 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putstr(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        write (1, &s[i], 1);
        i++;
    }
}
int     ft_putnbr(int n)
{
    long int	i;

	i = n;
	if (i < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	if (i >= 10)
	{
		ft_putnbr(i / 10);
	}
	ft_putchar(i % 10 + '0');
}
