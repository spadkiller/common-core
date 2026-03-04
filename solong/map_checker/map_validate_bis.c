/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:17:54 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/04 17:45:22 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"\

void map_count_cell(t_map *map, char c)
{
	if (c == PLAYER)
		map->player_count++;
	else if (c == EXIT)
		map->exit_count++;
	else if (c == COLLECTIBLE)
		map->collec_count++;
	else if (c == GHOST)
		map->ghost_count++;
}
