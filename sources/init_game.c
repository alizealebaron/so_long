/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:14:15 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/27 16:57:04 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game		*init_game(int argc, char **argv);
char		**init_map(char **argv, int size);
static void	init_obj(t_game *game);
static int	calcul_ligne(char **argv);

t_game	*init_game(int argc, char **argv)
{
	t_game	*game;

	check_error_param(argc, argv);
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->height = calcul_ligne(argv);
	game->map = init_map(argv, game->height);
	game->nb_moove = 0;
	game->minilbx = NULL;
	game->screen = NULL;
	init_obj(game);
	check_error_map(game, game->height);
	check_path(game, argv, game->height);
	game->width = ft_strlen(game->map[0]) - 1;
	return (game);
}

char	**init_map(char **argv, int size)
{
	char	**map;
	char	*line;
	int		fd;
	int		cpt;

	cpt = 0;
	line = "";
	fd = open(argv[1], O_RDONLY);
	map = ft_calloc((size + 1), sizeof(char *));
	while (line != NULL)
	{
		line = get_next_line(fd);
		map[cpt++] = line;
	}
	map[cpt] = NULL;
	return (map);
}

static int	calcul_ligne(char **argv)
{
	int		fd;
	int		nb_line;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	line = "";
	nb_line = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		nb_line++;
		free(line);
	}
	free(line);
	close(fd);
	return (nb_line);
}

static void	init_obj(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->objet = make_obj();
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				game->objet->nb_exit++;
			if (game->map[i][j] == 'C')
				game->objet->nb_patounes++;
			if (game->map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				game->objet->nb_player++;
			}
			j++;
		}
		i++;
	}
}

t_obj	*make_obj(void)
{
	t_obj	*obj;

	obj = malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	obj->nb_exit = 0;
	obj->nb_patounes = 0;
	obj->nb_player = 0;
	return (obj);
}
