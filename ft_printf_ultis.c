/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkyaw <htkyaw@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 16:16:58 by hkyawh            #+#    #+#             */
/*   Updated: 2026/09/24 11:10:37 by htkyaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	long int	i;
	int			len;

	i = nb;
	len = 0;
	if (i < 0)
	{
		ft_putchar('-');
		len++;
		i *= -1;
	}
	if (i >= 0 && i <= 9)
		len += ft_putchar(i + '0');
	if (i > 9)
	{
		len += ft_putnbr(i / 10);
		len += ft_putnbr(i % 10);
	}
	return (len);
}

int	ft_str(const char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

int	ft_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb <= 9)
	{
		len = len + ft_putchar(nb + '0');
	}
	if (nb > 9)
	{
		len = len + ft_unsigned(nb / 10);
		len = len + ft_unsigned(nb % 10);
	}
	return (len);
}

int	ft_hex(unsigned long v, char c)
{
	char	*base;
	int		len;

	len = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (v < 16)
		len += ft_putchar(base[v]);
	else
	{
		len += ft_hex(v / 16, c);
		len += ft_hex(v % 16, c);
	}
	return (len);
}
