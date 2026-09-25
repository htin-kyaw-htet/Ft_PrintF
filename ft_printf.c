/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkyaw <htkyaw@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 16:16:57 by hkyawh            #+#    #+#             */
/*   Updated: 2026/09/24 10:23:36 by htkyaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(void *ptr)
{
	unsigned long	p;
	int				len;

	if (!ptr)
		return (ft_str("(nil)"));
	p = (unsigned long)ptr;
	len = 0;
	len += ft_str("0x");
	len += ft_hex(p, 'x');
	return (len);
}

static int	ft_printf_conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_str(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_ptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		is_format;

	if (!format)
		return (-1);
	va_start(args, format);
	len = 0;
	while (*format)
	{
		is_format = (format[0] == '%' && format[1]);
		if (is_format)
			len += ft_printf_conversion(format[1], &args);
		else
			len += ft_putchar(*format);
		format += 1 + is_format;
	}
	va_end(args);
	return (len);
}
