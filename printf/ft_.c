/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:11:52 by gujarry           #+#    #+#             */
/*   Updated: 2025/12/02 12:03:50 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int ft_putchar(char c)
{
	write (1, &c, 1);
}
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
int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	addr;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	addr = (unsigned long)ptr;
	if (addr == 0)
		count += write(1, "0", 1);
	else
		count += put_hex(addr);
	return (count);
}
static int  ft_handle_format(char specifier, va_list args)
{
    int count;

    count = 0;
    if (specifier == 'c')
        count += ft_putchar(va_arg(args, int));
    else if (specifier == 's')
        count += ft_putstr(va_arg(args, char *));
    else if (specifier == 'p')
        count += ft_putptr(va_arg(args, void *));
    else if (specifier == 'd' || specifier == 'i')
        count += ft_putnbr(va_arg(args, int));
    else if (specifier == 'u')
        count += ft_putnbr_unsigned(va_arg(args, unsigned int));
    else if (specifier == 'x' || specifier == 'X')
        count += ft_puthex(va_arg(args, unsigned int), specifier);
    else if (specifier == '%')
        count += ft_putchar('%');
    return (count);
}
