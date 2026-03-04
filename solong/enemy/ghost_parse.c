/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:13:47 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/04 18:28:23 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

int	ghosts_collect_and_clear(t_game *g)
{
	int	x;
	int	y;
	int	i;

	g->ghost_count = g->map.ghost_count;
	g->ghosts = NULL;
	if (g->ghost_count <= 0)
		return (0);
	g->ghosts = malloc(sizeof(t_pos) * g->ghost_count);
	if (!g->ghosts)
		return (1);
	i = 0;
	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (g->map.grid[y][x] == GHOST)
			{
				g->ghosts[i].x = x;
				g->ghosts[i].y = y;
				g->map.grid[y][x] = EMPTY;
				i++;
			}
			x++;
		}
		y++;
	}
	return (0);
}
