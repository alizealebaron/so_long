/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:22:40 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/27 16:17:03 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_img_to_screen(t_game *game, void *sprite, int x, int y);
void	find_sprite(t_game *game, int x, int y);

void	init_visu_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height - 1)
	{
		x = 0;
		while (x < game->width)
		{
			find_sprite(game, x, y);
			x++;
		}
		y++;
	}
}

void	find_sprite(t_game *game, int x, int y)
{
	char	value;

	value = game->map[y][x];
	if (value == '1')
		put_img_to_screen(game, game->sprite->wall, x, y);
	if (value == '0')
		put_img_to_screen(game, game->sprite->floor, x, y);
	if (value == 'E')
		put_img_to_screen(game, game->sprite->door, x, y);
	if (value == 'C')
		put_img_to_screen(game, game->sprite->patounes, x, y);
	if (value == 'P')
		put_img_to_screen(game, game->sprite->player_left, x, y);
}

void	put_img_to_screen(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->minilbx, game->screen, \
	sprite, x * game->sprite->height, y * game->sprite->width);
}
