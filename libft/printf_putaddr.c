/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putaddr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:14:56 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/16 13:33:57 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_putaddr(unsigned long long p)
{
	char				c;
	int					len;
	char				*base;

	len = 0;
	base = "0123456789abcdef";
	if (!p)
		return (printf_putstr("(nil)"));
	if (p > 16 - 1)
	{
		len += printf_putaddr((p / 16));
	}
	if (len == 0)
	{
		len += printf_putstr("0x");
	}
	c = base[p % 16];
	len += printf_putchar(c);
	return (len);
}
