/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:09:03 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/27 16:55:59 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_collect(t_game *game);
static void	check_the_count(char **map, t_obj *objet, int x, int y);

void	check_error_param(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		send_error("Veuillez ajouter le nom de la map en argument.", NULL);
	if (ft_strlen(argv[1]) < 5)
		send_error("Le nom du fichier doit faire 5 caractères minimum.", NULL);
	if (!str_ber_terminated(argv[1]))
		send_error("Le nom du fichier doit se terminer par .ber", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		send_error("Fichier inexistant.", NULL);
	close(fd);
}

void	check_error_map(t_game *game, int size)
{
	int	i;
	int	len;
	int	len_act;

	i = 0;
	if (!game->map || !*game->map)
		send_error("Le fichier ne doit pas être vide.", game);
	len = ft_strlen(game->map[0]);
	while (game->map[i] != NULL)
	{
		len_act = ft_strlen(game->map[i]);
		if (len_act != len)
			send_error("Les lignes doivent être toutes de la même taille.",
				game);
		if (game->map[i][0] != '1' || game->map[i][len_act - 2] != '1')
			send_error("Les lignes doivent commencer et finir par des murs.",
				game);
		i++;
	}
	if (!check_wall(game->map[0]) || !check_wall(game->map[size - 2]))
		send_error("Les bordures nord ou / et sud sont incorrectes.", game);
	check_collect(game);
}

static void	check_collect(t_game *game)
{
	if (game->objet->nb_patounes < 1)
		send_error("La carte doit au moins avoir un collectible à ramasser.",
			game);
	if (game->objet->nb_exit != 1)
		send_error("La carte doit disposer d'une sortie maximum et minimum.",
			game);
	if (game->objet->nb_player != 1)
		send_error("Il est nécessaire d'avoir un joueur maximum et minimum.",
			game);
}

void	check_path(t_game *game, char **argv, int size)
{
	char	**map_dup;
	t_obj	*dup_obj;

	map_dup = init_map(argv, size);
	dup_obj = make_obj();
	check_the_count(map_dup, dup_obj, game->player.y, game->player.x);
	free_table_string(map_dup);
	if (dup_obj->nb_patounes != game->objet->nb_patounes)
	{
		free(dup_obj);
		send_error("Certaines patounes ne sont pas accessibles.", game);
	}
	if (dup_obj->nb_exit != 1)
	{
		free(dup_obj);
		send_error("La sortie n'est pas accessible.", game);
	}
	free(dup_obj);
}

static void	check_the_count(char **map, t_obj *objet, int x, int y)
{
	if (map[x][y] == '1')
		return ;
	if (map[x][y] == 'D')
		return ;
	if (map[x][y] == 'E')
	{
		map[x][y] = 'D';
		objet->nb_exit++;
		return ;
	}
	if (map[x][y] == 'C')
		objet->nb_patounes++;
	map[x][y] = 'D';
	check_the_count(map, objet, x - 1, y);
	check_the_count(map, objet, x + 1, y);
	check_the_count(map, objet, x, y + 1);
	check_the_count(map, objet, x, y - 1);
}
