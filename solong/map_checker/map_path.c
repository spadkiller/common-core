/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:57:15 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/26 20:03:56 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all.h"

static void	free_grid_copy(char **g)
{
	int	i;

	if (!g)
		return ;
	i = 0;
	while (g[i])
		free(g[i++]);
	free(g);
}

static char	**dup_grid(t_map *map)
{
	char	**copy;
	int		y;

	copy = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < map->height)
	{
		copy[y] = ft_strdup(map->grid[y]);
		if (!copy[y])
			return (free_grid_copy(copy), NULL);
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

static void	find_player(t_map *map, int *px, int *py)
{
	int	x;
	int	y;

	*px = -1;
	*py = -1;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == PLAYER)
			{
				*px = x;
				*py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	flood(char **g, t_map *map, int x, int y, int *c_ok, int *e_ok)
{
	char	cell;

	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	cell = g[y][x];
	if (cell == WALL || cell == 'V')
		return ;
	if (cell == COLLECTIBLE)
		(*c_ok)++;
	if (cell == EXIT)
		(*e_ok)++;
	g[y][x] = 'V';
	flood(g, map, x + 1, y, c_ok, e_ok);
	flood(g, map, x - 1, y, c_ok, e_ok);
	flood(g, map, x, y + 1, c_ok, e_ok);
	flood(g, map, x, y - 1, c_ok, e_ok);
}

int	map_check_path(t_map *map)
{
	char	**g;
	int		px;
	int		py;
	int		c_ok;
	int		e_ok;

	if (!map || !map->grid)
		return (1);
	find_player(map, &px, &py);
	if (px < 0 || py < 0)
		return (1);
	g = dup_grid(map);
	if (!g)
		return (1);
	c_ok = 0;
	e_ok = 0;
	flood(g, map, px, py, &c_ok, &e_ok);
	free_grid_copy(g);
	if (c_ok != map->collec_count)
		return (1);
	if (e_ok < 1)
		return (1);
	return (0);
}