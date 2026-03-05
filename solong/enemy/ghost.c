/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:54:18 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 11:34:08 by gujarry          ###   ########.fr       */
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

static int	can_enter_map(t_game *g, int x, int y)
{
	char	c;

	if (x < 0 || y < 0 || x >= g->map.width || y >= g->map.height)
		return (0);
	c = g->map.grid[y][x];
	if (c == WALL)
		return (0);
	return (1);
}

static int	is_occupied_by_any_ghost(t_game *g, t_pos *moved, int moved_count,
		int x, int y)
{
	int	j;

	j = 0;
	while (j < g->ghost_count)
	{
		if (g->ghosts[j].x == x && g->ghosts[j].y == y)
			return (1);
		j++;
	}
	j = 0;
	while (j < moved_count)
	{
		if (moved[j].x == x && moved[j].y == y)
			return (1);
		j++;
	}
	return (0);
}

static void	choose_best_step(t_game *g, t_pos *gh, t_pos *moved,
		int moved_count, int *out_x, int *out_y)
{
	int	best_x;
	int	best_y;
	int	best_d;
	int	d;
	int	nx[4];
	int	ny[4];
	int	i;

	best_x = gh->x;
	best_y = gh->y;
	best_d = manhattan(best_x, best_y, g->player_pos.x, g->player_pos.y);
	nx[0] = gh->x + 1;
	ny[0] = gh->y;
	nx[1] = gh->x - 1;
	ny[1] = gh->y;
	nx[2] = gh->x;
	ny[2] = gh->y + 1;
	nx[3] = gh->x;
	ny[3] = gh->y - 1;
	i = 0;
	while (i < 4)
	{
		if (can_enter_map(g, nx[i], ny[i]) && !is_occupied_by_any_ghost(g,
				moved, moved_count, nx[i], ny[i]))
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
	*out_x = best_x;
	*out_y = best_y;
}

static void	game_over(t_game *g)
{
	ft_putstr_fd("Game Over\n", 2);
	mlx_loop_end(g->mlx);
}

void	ghosts_step_towards_player(t_game *g)
{
	t_pos	*moved;
	int		i;
	int		nx;
	int		ny;

	if (!g || g->ghost_count <= 0 || !g->ghosts)
		return ;
	moved = (t_pos *)malloc(sizeof(t_pos) * g->ghost_count);
	if (!moved)
		return ;
	i = 0;
	while (i < g->ghost_count)
	{
		choose_best_step(g, &g->ghosts[i], moved, i, &nx, &ny);
		g->ghosts[i].x = nx;
		g->ghosts[i].y = ny;
		moved[i].x = nx;
		moved[i].y = ny;
		if (nx == g->player_pos.x && ny == g->player_pos.y)
		{
			free(moved);
			game_over(g);
			return ;
		}
		i++;
	}
	free(moved);
}
