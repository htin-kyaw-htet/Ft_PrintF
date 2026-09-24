/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkyaw <htkyaw@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 16:16:53 by hkyawh            #+#    #+#             */
/*   Updated: 2026/09/24 08:45:42 by htkyaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_str(const char *s);
int	ft_putnbr(int nb);
int	ft_unsigned(unsigned int nb);
int	ft_ptr(void *ptr);
int	ft_hex(unsigned long v, char specifier);
int	ft_printf(const char *format, ...);

#endif
