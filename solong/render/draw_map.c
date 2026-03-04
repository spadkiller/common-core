/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:58:56 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/04 15:51:12 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all.h"

static void	put(t_game *g, t_img *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img->ptr,
		x * g->tile, y * g->tile);
}

void	draw_map(t_game *g)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			c = g->map.grid[y][x];
			put(g, &g->sp.floor, x, y);
			if (c == WALL)
				put(g, &g->sp.wall, x, y);
			else if (c == COLLECTIBLE)
				put(g, &g->sp.collect, x, y);
			else if (c == EXIT)
				put(g, &g->sp.exit, x, y);
			x++;
		}
		y++;
	}
	put(g, &g->sp.player, g->player_pos.x, g->player_pos.y);
	if (g->ghost_pos.x >= 0 && g->ghost_pos.y >= 0)
		put(g, &g->sp.ghost, g->ghost_pos.x, g->ghost_pos.y);
}
