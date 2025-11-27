/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:04:05 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/27 16:57:16 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_minilibx(t_game *game)
{
	game->minilbx = mlx_init();
	if (game->minilbx == NULL)
	{
		free(game->minilbx);
		send_error("Erreur lors de l'initialisation de la minilibx.", game);
	}
	game->sprite = init_sprite(game);
	if (game->sprite == NULL)
	{
		free(game->minilbx);
		send_error("Échec du chargement des sprites", game);
	}
	game->screen = mlx_new_window(game->minilbx,
			(game->width) * game->sprite->width,
			(game->height - 1) * game->sprite->height, "Titre");
	if (game->screen == NULL)
	{
		free(game->screen);
		send_error("Erreur lors de la création de la fenêtre.", game);
	}
}

t_sprite	*init_sprite(t_game	*game)
{
	t_sprite	*sprite;

	sprite = malloc (sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->height = 32;
	sprite->width = 32;
	sprite->floor = mlx_xpm_file_to_image(game->minilbx,
			"textures/floor.xpm", &sprite->width, &sprite->height);
	sprite->wall = mlx_xpm_file_to_image(game->minilbx, "textures/wall.xpm",
			&sprite->width, &sprite->height);
	sprite->player_left = mlx_xpm_file_to_image(game->minilbx,
			"textures/duck_left.xpm", &sprite->width, &sprite->height);
	sprite->player_right = mlx_xpm_file_to_image(game->minilbx,
			"textures/duck_right.xpm", &sprite->width, &sprite->height);
	sprite->patounes = mlx_xpm_file_to_image(game->minilbx,
			"textures/worm.xpm", &sprite->width, &sprite->height);
	sprite->door = mlx_xpm_file_to_image(game->minilbx,
			"textures/water.xpm", &sprite->width, &sprite->height);
	return (sprite);
}
