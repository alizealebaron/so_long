/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:09:08 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/27 16:54:36 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	str_ber_terminated(char *s)
{
	int	l;

	l = ft_strlen(s);
	return (s[l - 1] == 'r' && s[l - 2] == 'e' && s[l - 3] == 'b'
		&& s[l - 4] == '.');
}

int	check_wall(char *s)
{
	while (*s != '\0')
	{
		if (*s != '1' && *s != '\n')
			return (0);
		s++;
	}
	return (1);
}
