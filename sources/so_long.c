/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:37:57 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/27 17:19:10 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = init_game(argc, argv);
	if (!game)
		send_error("Le jeu ne s'est pas correctement initialisé.", NULL);
	init_minilibx(game);
	init_visu_map(game);
	mlx_hook(game->screen, KeyPress, KeyPressMask, &key_listener, game);
	mlx_hook(game->screen, 17, 0, destroy_loop, game);
	mlx_loop(game->minilbx);
	free_all_game(game);
}
