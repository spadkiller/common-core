/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:44:26 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 15:23:41 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "enemy/enemy.h"
#include "map_checker/map_checker.h"
#include "libft/libft.h"

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

int	init_map_and_entities(t_game *g, const char *map_path)
{
	if (map_check(&g->map, map_path) != 0)
		return (ft_putstr_fd("Error\nInvalid map\n", 2), 1);
	find_player_and_clear(g);
	if (ghosts_collect_and_clear(g) != 0)
		return (1);
	return (0);
}
int	start_game(const char *map_path);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr_fd("Usage: ./so_long map.ber\n", 2), 1);
	return (start_game(argv[1]));
}
