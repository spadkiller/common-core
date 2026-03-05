/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:13:47 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 13:03:35 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static int	alloc_ghosts(t_game *g)
{
	g->ghost_count = g->map.ghost_count;
	g->ghosts = NULL;
	if (g->ghost_count <= 0)
		return (0);
	g->ghosts = (t_pos *)malloc(sizeof(t_pos) * g->ghost_count);
	if (!g->ghosts)
		return (1);
	return (0);
}

static void	fill_ghosts(t_game *g)
{
	int	x;
	int	y;
	int	i;

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
}

int	ghosts_collect_and_clear(t_game *g)
{
	if (!g)
		return (1);
	if (alloc_ghosts(g) != 0)
		return (1);
	if (g->ghost_count > 0)
		fill_ghosts(g);
	return (0);
}
