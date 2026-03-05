/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:57:15 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 13:13:58 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

static void	free_grid_copy(char **g)
{
	int	i;

	i = 0;
	while (g && g[i])
	{
		free(g[i]);
		i++;
	}
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

static int	find_player(t_map *map, int *px, int *py)
{
	int	x;
	int	y;

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
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	map_check_path(t_map *map)
{
	char	**g;
	int		px;
	int		py;

	if (!map || !map->grid)
		return (1);
	if (find_player(map, &px, &py) != 0)
		return (1);
	g = dup_grid(map);
	if (!g)
		return (1);
	if (map_flood_check(g, map, px, py) != 0)
		return (free_grid_copy(g), 1);
	free_grid_copy(g);
	return (0);
}
