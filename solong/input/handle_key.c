/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:27:17 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/11 11:04:25 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all.h"
#include "../enemy/enemy.h"
#include "../render/render.h"
#include "input.h"

static int	try_move_player(t_game *g, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = g->player_pos.x + dx;
	ny = g->player_pos.y + dy;
	if (!can_enter_cell(g, nx, ny))
		return (0);
	if (is_ghost_at(g, nx, ny))
		return (game_over(g), 0);
	if (g->map.grid[ny][nx] == COLLECTIBLE)
		g->map.grid[ny][nx] = EMPTY;
	if (g->map.grid[ny][nx] == EXIT && count_collect_left(g) == 0)
		return (mlx_loop_end(g->mlx), 0);
	g->player_pos.x = nx;
	g->player_pos.y = ny;
	g->moves++;
	return (1);
}

int	handle_key(int keycode, t_game *g)
{
	int	moved;

	if (keycode == KEY_ESC)
		return (mlx_loop_end(g->mlx), 0);
	moved = 0;
	if (keycode == KEY_W || keycode == KEY_UP)
		moved = try_move_player(g, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		moved = try_move_player(g, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		moved = try_move_player(g, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		moved = try_move_player(g, 1, 0);
	if (moved)
	{
		ghosts_step_towards_player(g);
		draw_map(g);
	}
	return (0);
}
