/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:57:31 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/26 21:57:09 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

void	map_free(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (map->grid[i])
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	map->grid = NULL;
}