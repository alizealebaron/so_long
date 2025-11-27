/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:02:55 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/27 17:18:52 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	destroy_loop(t_game *game)
{
	mlx_loop_end(game->minilbx);
	return (0);
}

void	free_all_game(t_game *game)
{
	free_pictures(game);
	if (game->screen)
		mlx_destroy_window(game->minilbx, game->screen);
	if (game->minilbx)
	{
		mlx_destroy_display(game->minilbx);
		free(game->minilbx);
	}
	if (game->map)
		free_table_string(game->map);
	free(game->objet);
	free(game->sprite);
	free(game);
}

void	free_pictures(t_game *game)
{
	if (game->sprite->player_left)
		mlx_destroy_image(game->minilbx, game->sprite->player_left);
	if (game->sprite->player_right)
		mlx_destroy_image(game->minilbx, game->sprite->player_right);
	if (game->sprite->door)
		mlx_destroy_image(game->minilbx, game->sprite->door);
	if (game->sprite->wall)
		mlx_destroy_image(game->minilbx, game->sprite->wall);
	if (game->sprite->patounes)
		mlx_destroy_image(game->minilbx, game->sprite->patounes);
	if (game->sprite->floor)
		mlx_destroy_image(game->minilbx, game->sprite->floor);
}
