/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:45:16 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/25 15:04:01 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

int	map_check(t_map *map, const char *path)
{
	if (map_load(map, path) != 0)
		return (1);
	if (map_validate(map) != 0)
	{
		map_free(map);
		return (1);
	}
	return (0);
}