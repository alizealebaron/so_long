/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:19:14 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/16 13:34:14 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_putstr(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (printf_putstr("(null)"));
	while (*s)
		len += printf_putchar(*s++);
	return (len);
}
