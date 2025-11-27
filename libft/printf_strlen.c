/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:25:35 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/16 13:34:17 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_strlen(char *s)
{
	int	somme;

	somme = 0;
	while (s[somme])
		somme++;
	return (somme);
}
