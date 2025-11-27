/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:26:11 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/27 16:19:20 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// ==========================
//         Includes
// ==========================

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

// ==========================
//      Valeurs touches
// ==========================

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// ==========================
//         Structures
// ==========================

typedef struct s_coord
{
	int			x;
	int			y;
}			t_coord;

typedef struct s_obj
{
	int			nb_exit;
	int			nb_patounes;
	int			nb_player;
}			t_obj;

typedef struct s_sprite
{
	int		height;
	int		width;
	void	*player_left;
	void	*player_right;
	void	*floor;
	void	*wall;
	void	*patounes;
	void	*door;
}			t_sprite;

typedef struct s_game
{
	char		**map;
	int			height;
	int			width;
	t_coord		player;
	t_obj		*objet;
	t_sprite	*sprite;
	void		*minilbx;
	void		*screen;
	int			nb_moove;
}			t_game;

// ==========================
//       Initialisation
// ==========================

t_game		*init_game(int argc, char **argv);
char		**init_map(char **argv, int size);
void		init_minilibx(t_game *game);
t_sprite	*init_sprite(t_game	*game);
void		init_visu_map (t_game *game);
t_obj		*make_obj(void);

// ==========================
//          Listener
// ==========================

int			key_listener(int key, t_game *game);

// ==========================
//          Affichage
// ==========================

void		put_img_to_screen(t_game *game, void *sprite, int x, int y);

// ==========================
//      Gestion erreurs
// ==========================

void		send_error(char *error, t_game *game);
void		send_error_minilx(char *error, t_game *game);

void		check_error_param(int argc, char **argv);
void		check_error_map(t_game *game, int size);
void		check_path(t_game *game, char **argv, int size);

int			str_ber_terminated(char *s);
int			check_wall(char *s);

// ==========================
//           Free
// ==========================

char		**free_table_string(char **s);
void		free_without_lbx(t_game *game);
void		free_all_game(t_game *game);
void		free_pictures(t_game *game);

int			destroy_loop(t_game *game);

#endif