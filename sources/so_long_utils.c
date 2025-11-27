/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:26:04 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/27 17:18:34 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	send_error(char *error, t_game *game)
{
	if (game)
		free_without_lbx(game);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	exit(0);
}

void	send_error_minilx(char *error, t_game *game)
{
	if (game)
		free_all_game(game);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	exit(0);
}

char	**free_table_string(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

void	free_without_lbx(t_game *game)
{
	free_table_string(game->map);
	free(game->objet);
	free(game);
}
