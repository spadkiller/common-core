/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:56:59 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 15:22:35 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

static int	count_and_charset(t_map *map)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->grid[y][x];
			if (!map_is_valid_char(c))
				return (1);
			map_count_cell(map, c);
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
	if (map->width <= 0)
		map->width = (int)ft_strlen(map->grid[0]);
	if (map_check_rectangle(map) != 0)
		return (1);
	if (map->width > 200 || map->height > 200)
		return (1);
	if (map_check_walls(map) != 0)
		return (1);
	if (count_and_charset(map) != 0)
		return (1);
	if (map->player_count != 1 || map->exit_count != 1)
		return (1);
	if (map->collec_count < 1)
		return (1);
	if (map->width > 200 || map->height > 200)
		return (1);
	return (0);
}
