/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:27:17 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 11:33:35 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../enemy/enemy.h"
#include "../printf/ft_printf.h"
#include "input.h"

static int	count_collect_left(t_game *g)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (g->map.grid[y][x] == COLLECTIBLE)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static int	is_ghost_at(t_game *g, int x, int y)
{
	int	i;

	i = 0;
	while (i < g->ghost_count)
	{
		if (g->ghosts[i].x == x && g->ghosts[i].y == y)
			return (1);
		i++;
	}
	return (0);
}

static void	game_over(t_game *g)
{
	ft_putstr_fd("Game Over\n", 2);
	mlx_loop_end(g->mlx);
}

static int	can_enter_cell(t_game *g, int nx, int ny)
{
	char	dest;

	if (nx < 0 || ny < 0 || nx >= g->map.width || ny >= g->map.height)
		return (0);
	dest = g->map.grid[ny][nx];
	if (dest == WALL)
		return (0);
	if (dest == EXIT && count_collect_left(g) != 0)
		return (0);
	return (1);
}

static int	try_move_player(t_game *g, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = g->player_pos.x + dx;
	ny = g->player_pos.y + dy;
	if (!can_enter_cell(g, nx, ny))
		return (0);
	if (is_ghost_at(g, nx, ny))
	{
		game_over(g);
		return (0);
	}
	if (g->map.grid[ny][nx] == COLLECTIBLE)
		g->map.grid[ny][nx] = EMPTY;
	if (g->map.grid[ny][nx] == EXIT && count_collect_left(g) == 0)
	{
		ft_putstr_fd("You win!\n", 1);
		mlx_loop_end(g->mlx);
		return (0);
	}
	g->player_pos.x = nx;
	g->player_pos.y = ny;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
	return (1);
}

int	handle_key(int keycode, t_game *g)
{
	int	moved;

	if (!g)
		return (0);
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(g->mlx);
		return (0);
	}
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
