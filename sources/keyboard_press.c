/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:53:59 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/27 17:00:12 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	moove_duck(t_game *game, int new_x, int new_y);
static void	print_win(t_game *game);
static void	print_moove(t_game *game);

int	key_listener(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		ft_printf("Fermeture du jeu !\n");
		destroy_loop(game);
	}
	if (key == KEY_A)
		moove_duck(game, game->player.x - 1, game->player.y);
	if (key == KEY_W)
		moove_duck(game, game->player.x, game->player.y - 1);
	if (key == KEY_S)
		moove_duck(game, game->player.x, game->player.y + 1);
	if (key == KEY_D)
		moove_duck(game, game->player.x + 1, game->player.y);
	return (0);
}

static void	moove_duck(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = game->player.x;
	old_y = game->player.y;
	if (game->map[new_y][new_x] == 'E' && game->objet->nb_patounes == 0)
		print_win(game);
	if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'C')
	{
		game->map[old_y][old_x] = '0';
		if (game->map[new_y][new_x] == 'C')
			game->objet->nb_patounes--;
		game->player.x = new_x;
		game->player.y = new_y;
		game->map[new_y][new_x] = 'P';
		game->nb_moove++;
		put_img_to_screen(game, game->sprite->player_left, new_x, new_y);
		put_img_to_screen(game, game->sprite->floor, old_x, old_y);
		print_moove(game);
	}
}

static void	print_win(t_game *game)
{
	game->nb_moove++;
	print_moove(game);
	ft_printf("\033[33m\033[1m");
	ft_printf("  _      _      _   \n");
	ft_printf(">(.)__ <(.)__ =(^)__\n");
	ft_printf(" (___/  (___/  (___/\n\n");
	ft_printf("\033[0m");
	ft_printf("Vous avez gagné :D\n");
	destroy_loop(game);
}

static void	print_moove(t_game *game)
{
	ft_printf("Nombre de mouvement : %d\n", game->nb_moove);
}
