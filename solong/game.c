/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:06:58 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/26 21:23:53 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"

static void	find_player(t_game *g)
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
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	close_game(t_game *g)
{
	destroy_sprites(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	map_free(&g->map);
	exit(0);
	return (0);
}

int	start_game(const char *map_path)
{
	t_game	g;

	g.tile = 32;
	g.moves = 0;
	g.mlx = NULL;
	g.win = NULL;
	if (map_check(&g.map, map_path) != 0)
		return (ft_putstr_fd("Error\nInvalid map\n", 2), 1);
	find_player(&g);
	g.mlx = mlx_init();
	if (!g.mlx)
		return (map_free(&g.map), 1);
	g.win = mlx_new_window(g.mlx, g.map.width * g.tile,
			g.map.height * g.tile, "so_long");
	if (!g.win)
		return (map_free(&g.map), 1);
	if (load_sprites(&g) != 0)
		return (ft_putstr_fd("Error\nXPM load failed\n", 2), close_game(&g), 1);
	draw_map(&g);
	mlx_hook(g.win, DESTROY_NOTIFY, 0, close_game, &g);
	mlx_key_hook(g.win, handle_key, &g);
	mlx_loop(g.mlx);
	close_game(&g);
	return (0);
}
