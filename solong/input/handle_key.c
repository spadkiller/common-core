/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:27:17 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/26 21:33:22 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

static int	count_collect_left(t_game *g)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (g->map.grid[y][x] == COLLECTIBLE)
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

static int	can_enter_cell(t_game *g, char dest)
{
	if (dest == WALL)
		return (0);
	if (dest == EXIT && count_collect_left(g) != 0)
		return (0);
	return (1);
}

static void	apply_player_move(t_game *g, int nx, int ny)
{
	g->map.grid[g->player_pos.y][g->player_pos.x] = EMPTY;
	g->player_pos.x = nx;
	g->player_pos.y = ny;
	g->map.grid[ny][nx] = PLAYER;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
}

static void	try_move(t_game *g, int dx, int dy)
{
	int		nx;
	int		ny;
	char	dest;

	nx = g->player_pos.x + dx;
	ny = g->player_pos.y + dy;
	dest = g->map.grid[ny][nx];
	if (!can_enter_cell(g, dest))
		return ;
	if (dest == EXIT && count_collect_left(g) == 0)
	{
		g->moves++;
		ft_printf("Moves: %d\n", g->moves);
		mlx_loop_end(g->mlx);
		return ;
	}
	apply_player_move(g, nx, ny);
	draw_map(g);
}

int	handle_key(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		return (mlx_loop_end(g->mlx), 0);
	if (keycode == KEY_W)
		try_move(g, 0, -1);
	else if (keycode == KEY_S)
		try_move(g, 0, 1);
	else if (keycode == KEY_A)
		try_move(g, -1, 0);
	else if (keycode == KEY_D)
		try_move(g, 1, 0);
	return (0);
}
