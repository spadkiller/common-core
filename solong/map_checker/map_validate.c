/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:56:59 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/25 15:23:55 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

static int	is_valid_char(char c)
{
	return (c == WALL || c == EMPTY || c == PLAYER || c == EXIT
		|| c == COLLECTIBLE);
}

static int	check_rectangle(t_map *map)
{
	int		y;
	size_t	w;

	w = ft_strlen(map->grid[0]);
	if (w == 0)
		return (1);
	y = 0;
	while (map->grid[y])
	{
		if (ft_strlen(map->grid[y]) != w)
			return (1);
		y++;
	}
	map->width = (int)w;
	map->height = y;
	return (0);
}

static int	check_walls(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != WALL || map->grid[map->height - 1][x] != WALL)
			return (1);
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][0] != WALL || map->grid[y][map->width - 1] != WALL)
			return (1);
		y++;
	}
	return (0);
}

static int	count_and_charset(t_map *map)
{
	int	x;
	int	y;
	char	c;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->grid[y][x];
			if (!is_valid_char(c))
				return (1);
			if (c == PLAYER)
				map->player_count++;
			else if (c == EXIT)
				map->exit_count++;
			else if (c == COLLECTIBLE)
				map->collec_count++;
			x++;
		}
		y++;
	}
	return (0);
}

int	map_validate(t_map *map)
{
	if (!map || !map->grid || !map->grid[0])
		return (1);
	if (check_rectangle(map) != 0)
		return (1);
	if (check_walls(map) != 0)
		return (1);
	if (count_and_charset(map) != 0)
		return (1);
	if (map->player_count != 1)
		return (1);
	if (map->exit_count < 1)
		return (1);
	if (map->collec_count < 1)
		return (1);
	return (0);
}