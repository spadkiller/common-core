/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:38:15 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 12:39:16 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ghost_internal.h"

static int	iabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ghost_can_enter(t_game *g, int x, int y)
{
	char	c;

	if (x < 0 || y < 0 || x >= g->map.width || y >= g->map.height)
		return (0);
	c = g->map.grid[y][x];
	if (c == WALL)
		return (0);
	return (1);
}

static int	manhattan(int ax, int ay, int bx, int by)
{
	return (iabs(ax - bx) + iabs(ay - by));
}

int	ghost_is_occupied(t_ghost_step *st, int x, int y)
{
	int	j;

	j = 0;
	while (j < st->g->ghost_count)
	{
		if (st->g->ghosts[j].x == x && st->g->ghosts[j].y == y)
			return (1);
		j++;
	}
	j = 0;
	while (j < st->moved_count)
	{
		if (st->moved[j].x == x && st->moved[j].y == y)
			return (1);
		j++;
	}
	return (0);
}

int	ghost_dist_to_player(t_game *g, int x, int y)
{
	return (manhattan(x, y, g->player_pos.x, g->player_pos.y));
}