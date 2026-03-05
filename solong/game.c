/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:06:58 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 15:01:58 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "enemy/enemy.h"
#include "input/input.h"
#include "libft/libft.h"
#include "map_checker/map_checker.h"
#include "render/render.h"

int			init_map_and_entities(t_game *g, const char *map_path);
int			window_too_big(t_game *g);

static void	cleanup_game(t_game *g)
{
	destroy_sprites(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	free(g->ghosts);
	g->ghosts = NULL;
	g->ghost_count = 0;
	map_free(&g->map);
}

static int	close_game(t_game *g)
{
	cleanup_game(g);
	exit(0);
	return (0);
}

static int	init_mlx_and_window(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		return (cleanup_game(g), 1);
	if (window_too_big(g))
		return (ft_putstr_fd("Error\nMap too big\n", 2), cleanup_game(g), 1);
	g->win = mlx_new_window(g->mlx, g->map.width * g->tile, g->map.height
			* g->tile, "so_long");
	if (!g->win)
		return (cleanup_game(g), 1);
	return (0);
}

int	start_game(const char *map_path)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	g.tile = 32;
	if (init_map_and_entities(&g, map_path) != 0)
		return (1);
	if (init_mlx_and_window(&g) != 0)
		return (1);
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
