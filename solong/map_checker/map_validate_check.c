/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:20:36 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 12:26:23 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

int	map_check_rectangle(t_map *map)
{
	int	y;

	if (!map->grid[0] || ft_strlen(map->grid[0]) == 0)
		return (1);
	y = 0;
	while (map->grid[y])
	{
		if ((int)ft_strlen(map->grid[y]) != map->width)
			return (1);
		y++;
	}
	map->height = y;
	return (0);
}

int	map_check_walls(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != WALL
			|| map->grid[map->height - 1][x] != WALL)
			return (1);
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][0] != WALL
			|| map->grid[y][map->width - 1] != WALL)
			return (1);
		y++;
	}
	return (0);
}