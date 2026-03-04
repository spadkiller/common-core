/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:54:18 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/04 15:55:01 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"

static int	iabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	manhattan(int ax, int ay, int bx, int by)
{
	return (iabs(ax - bx) + iabs(ay - by));
}

static int	ghost_can_enter(t_game *g, int x, int y)
{
	char	c;

	if (x < 0 || y < 0 || x >= g->map.width || y >= g->map.height)
		return (0);
	c = g->map.grid[y][x];
	if (c == WALL)
		return (0);
	return (1);
}

void	ghost_step_towards_player(t_game *g)
{
	int	best_x;
	int	best_y;
	int	best_d;
	int	d;
	int	nx[4];
	int	ny[4];
	int	i;

	if (g->ghost_pos.x < 0 || g->ghost_pos.y < 0)
		return ;
	best_x = g->ghost_pos.x;
	best_y = g->ghost_pos.y;
	best_d = manhattan(best_x, best_y, g->player_pos.x, g->player_pos.y);
	nx[0] = g->ghost_pos.x + 1; ny[0] = g->ghost_pos.y;
	nx[1] = g->ghost_pos.x - 1; ny[1] = g->ghost_pos.y;
	nx[2] = g->ghost_pos.x;     ny[2] = g->ghost_pos.y + 1;
	nx[3] = g->ghost_pos.x;     ny[3] = g->ghost_pos.y - 1;
	i = 0;
	while (i < 4)
	{
		if (ghost_can_enter(g, nx[i], ny[i]))
		{
			d = manhattan(nx[i], ny[i], g->player_pos.x, g->player_pos.y);
			if (d < best_d)
			{
				best_d = d;
				best_x = nx[i];
				best_y = ny[i];
			}
		}
		i++;
	}
	g->ghost_pos.x = best_x;
	g->ghost_pos.y = best_y;
	if (g->ghost_pos.x == g->player_pos.x && g->ghost_pos.y == g->player_pos.y)
		mlx_loop_end(g->mlx);
}
