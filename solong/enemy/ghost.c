/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:54:18 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 13:05:00 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ghost_internal.h"

static void	game_over(t_game *g)
{
	ft_putstr_fd("Game Over\n", 2);
	mlx_loop_end(g->mlx);
}

static int	step_one(t_ghost_step *st, int i)
{
	int	nx;
	int	ny;

	ghost_choose_step(st, &st->g->ghosts[i], &nx, &ny);
	st->g->ghosts[i].x = nx;
	st->g->ghosts[i].y = ny;
	st->moved[i].x = nx;
	st->moved[i].y = ny;
	if (nx == st->g->player_pos.x && ny == st->g->player_pos.y)
		return (1);
	return (0);
}

void	ghosts_step_towards_player(t_game *g)
{
	t_ghost_step	st;
	int				i;

	if (!g || g->ghost_count <= 0 || !g->ghosts)
		return ;
	st.g = g;
	st.moved = (t_pos *)malloc(sizeof(t_pos) * g->ghost_count);
	if (!st.moved)
		return ;
	st.moved_count = 0;
	i = 0;
	while (i < g->ghost_count)
	{
		if (step_one(&st, i))
			return (free(st.moved), game_over(g));
		st.moved_count++;
		i++;
	}
	free(st.moved);
}
