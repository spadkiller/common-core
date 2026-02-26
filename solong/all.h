/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:47:13 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/26 21:24:21 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "minilibx-linux/mlx.h"
#include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_SPACE 32

# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define DESTROY_NOTIFY 17

# define DIR_UP 0
# define DIR_DOWN 1
# define DIR_LEFT 2
# define DIR_RIGHT 3

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_player
{
	t_pos	player_pos;
	int		direction;
	t_pos	next_pos;
}			t_player;

typedef struct s_enemy
{
	int		direction;
	t_pos	enemy_pos;
	t_pos	enemy_next_pos;
}			t_enemy;

typedef struct s_collec
{
	t_pos	collec_pos;
}			t_collec;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collec_count;
}			t_map;

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_sprites
{
	t_img	floor;
	t_img	wall;
	t_img	player;
	t_img	exit;
	t_img	collect;
}	t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			tile;
	int			moves;
	t_pos		player_pos;
	t_map		map;
	t_sprites	sp;
}	t_game;

//map checker
int		map_load(t_map *map, const char *path);
int		map_validate(t_map *map);
int		map_check(t_map *map, const char *path);
void	map_free(t_map *map);
int		map_check_path(t_map *map);
//render
int		load_sprites(t_game *g);
void	draw_map(t_game *g);
void	destroy_sprites(t_game *g);
//input
int	handle_key(int keycode, t_game *g);

#endif