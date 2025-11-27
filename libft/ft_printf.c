/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:14:30 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/16 13:33:52 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_args(char c, va_list args);

int	ft_printf(const char *str, ...)
{
	int			ret_printf;
	va_list		args;

	ret_printf = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			ret_printf += find_args(*(str + 1), args);
			str++;
		}
		else
		{
			ret_printf += printf_putchar(*str);
		}
		str++;
	}
	va_end (args);
	return (ret_printf);
}

static int	find_args(char c, va_list args)
{
	if (c == 'c')
		return (printf_putchar(va_arg(args, int)));
	else if (c == 's')
		return (printf_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (printf_putaddr(va_arg(args, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (printf_putnbr_base(va_arg(args, int), "0123456789"));
	else if (c == 'u')
		return (printf_pnbr(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (printf_pnbr(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (printf_pnbr(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (printf_putchar('%'));
	else
		return (0);
}
