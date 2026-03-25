/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:58:56 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/11 11:39:42 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all.h"
#include "../libft/libft.h"

static void	put(t_game *g, t_img *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img->ptr,
		x * g->tile, y * g->tile);
}

static void	draw_moves(t_game *g)
{
	char	*s;

	s = ft_itoa(g->moves);
	if (!s)
		return ;
	mlx_string_put(g->mlx, g->win, 10, 20, 0xFFFFFF, "Moves:");
	mlx_string_put(g->mlx, g->win, 70, 20, 0xFFFFFF, s);
	free(s);
}

static void	draw_tiles(t_game *g)
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
				put(g, &g->sp.collect_anim[g->anim_frame], x, y);
			else if (c == EXIT)
				put(g, &g->sp.exit, x, y);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *g)
{
	int	i;

	draw_tiles(g);
	put(g, &g->sp.player, g->player_pos.x, g->player_pos.y);
	i = 0;
	while (i < g->ghost_count)
	{
		put(g, &g->sp.ghost, g->ghosts[i].x, g->ghosts[i].y);
		i++;
	}
	draw_moves(g);
}
