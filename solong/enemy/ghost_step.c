/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:57:24 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 12:57:48 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ghost_internal.h"

static void	init_best(t_ghost_best *b, t_game *g, t_pos *gh)
{
	b->best_x = gh->x;
	b->best_y = gh->y;
	b->best_d = ghost_dist(g, gh->x, gh->y);
}

static void	try_dir(t_ghost_step *st, t_ghost_best *b, int x, int y)
{
	int	d;

	if (!ghost_can_enter(st->g, x, y))
		return ;
	if (ghost_is_occupied(st, x, y))
		return ;
	d = ghost_dist(st->g, x, y);
	if (d < b->best_d)
	{
		b->best_d = d;
		b->best_x = x;
		b->best_y = y;
	}
}

void	ghost_choose_step(t_ghost_step *st, t_pos *gh, int *out_x, int *out_y)
{
	t_ghost_best	b;

	init_best(&b, st->g, gh);
	try_dir(st, &b, gh->x + 1, gh->y);
	try_dir(st, &b, gh->x - 1, gh->y);
	try_dir(st, &b, gh->x, gh->y + 1);
	try_dir(st, &b, gh->x, gh->y - 1);
	*out_x = b.best_x;
	*out_y = b.best_y;
}
