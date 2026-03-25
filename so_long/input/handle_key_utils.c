/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:29:42 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 13:29:53 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all.h"
#include "../libft/libft.h"

int	count_collect_left(t_game *g)
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

int	is_ghost_at(t_game *g, int x, int y)
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

void	game_over(t_game *g)
{
	ft_putstr_fd("Game Over\n", 2);
	mlx_loop_end(g->mlx);
}

int	can_enter_cell(t_game *g, int nx, int ny)
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
