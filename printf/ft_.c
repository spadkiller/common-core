/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:11:52 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/24 15:42:26 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/gujarry/Documents/Common-Core-Git/libft/libft.h"
#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
}
int	ft_puthex(unsigned long n, char format)
{
	int		count;
	char	*base;

	count = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	count += ft_putchar(base[n % 16]);
	return (count);
}
void	ft_putptr(void *ptr)
{
    int             count;
    unsigned long   address;

    count = 0;
    if (!ptr)
        return (ft_putstr("(nil)"));
    address = (unsigned long)ptr;
    count += ft_putstr("0x");
    count += ft_puthex(address, 'x');
    return (count);
}