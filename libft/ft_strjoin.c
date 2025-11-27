/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:26:02 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/20 11:28:03 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str_join;

	j = 0;
	i = 0;
	k = 0;
	str_join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str_join)
		return (NULL);
	while (s1[i] != '\0')
	{
		str_join[k] = s1[i];
		i++;
		k++;
	}
	while (s2[j] != '\0')
	{
		str_join[k] = s2[j];
		j++;
		k++;
	}
	str_join[k] = '\0';
	return (str_join);
}
