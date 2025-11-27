/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:19:08 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/16 13:34:09 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_putnbr_base(int nbr, char *base)
{
	int		length_base;
	char	c;
	long	nb;
	int		len;

	nb = nbr;
	len = 0;
	length_base = printf_strlen(base);
	if (nb < 0)
	{
		len += printf_putchar('-');
		nb = -nb;
	}
	if (nb > length_base - 1)
	{
		len += printf_putnbr_base((int)(nb / length_base), base);
	}
	c = base[nb % length_base];
	len += printf_putchar(c);
	return (len);
}
