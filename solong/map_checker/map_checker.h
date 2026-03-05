/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:30:29 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 15:16:38 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKER_H
# define MAP_CHECKER_H

# include "../all.h"

int			map_load(t_map *map, const char *path);
int			map_validate(t_map *map);
int			map_check_path(t_map *map);

int			map_check(t_map *map, const char *path);
void		map_free(t_map *map);

int			map_check_rectangle(t_map *map);
int			map_check_walls(t_map *map);
int			map_is_valid_char(char c);
void		map_count_cell(t_map *map, char c);

int			map_flood_check(char **g, t_map *map, int px, int py);
void		map_init(t_map *map);
int			map_push_line(t_map *map, char *line);
static int	is_dot_ber(const char *path);

typedef struct s_flood
{
	char	**g;
	t_map	*map;
	t_pos	*st;
	int		top;
	int		max;
	int		c_ok;
	int		e_ok;
}			t_flood;

#endif