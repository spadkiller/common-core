/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:11:02 by gujarry           #+#    #+#             */
/*   Updated: 2025/12/02 14:59:14 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthex(unsigned long n, char format);
int	ft_putptr(void *ptr);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_printf(const char *format, ...);

#endif
