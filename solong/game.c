/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:06:58 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/04 18:17:42 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "input/input.h"
#include "libft/libft.h"
#include "map_checker/map_checker.h"
#include "render/render.h"

static void	find_player_and_clear(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (g->map.grid[y][x] == PLAYER)
			{
				g->player_pos.x = x;
				g->player_pos.y = y;
				g->map.grid[y][x] = EMPTY;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	cleanup_game(t_game *g)
{
	destroy_sprites(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	free(g->ghosts);
	g->ghosts = NULL;
	map_free(&g->map);
}

static int	close_game(t_game *g)
{
	cleanup_game(g);
	exit(0);
	return (0);
}
static void	find_ghost_and_clear(t_game *g)
{
	int	x;
	int	y;

	g->ghosts.x = -1;
	g->ghosts.y = -1;
	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (g->map.grid[y][x] == GHOST)
			{
				g->ghosts.x = x;
				g->ghosts.y = y;
				g->map.grid[y][x] = EMPTY;
				return ;
			}
			x++;
		}
		y++;
	}
}
int	start_game(const char *map_path)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	g.tile = 32;
	if (map_check(&g.map, map_path) != 0)
		return (ft_putstr_fd("Error\nInvalid map\n", 2), 1);
	find_player_and_clear(&g);
	if (ghosts_collect_and_clear(&g) != 0)
		return (cleanup_game(&g), 1);
	g.mlx = mlx_init();
	if (!g.mlx)
		return (map_free(&g.map), 1);
	g.win = mlx_new_window(g.mlx, g.map.width * g.tile, g.map.height * g.tile,
			"so_long");
	if (!g.win)
		return (cleanup_game(&g), 1);
	if (load_sprites(&g) != 0)
		return (ft_putstr_fd("Error\nXPM load failed\n", 2), cleanup_game(&g),
			1);
	draw_map(&g);
	mlx_hook(g.win, DESTROY_NOTIFY, 0, close_game, &g);
	mlx_key_hook(g.win, handle_key, &g);
	mlx_loop(g.mlx);
	close_game(&g);
	return (0);
}
