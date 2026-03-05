/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:34:24 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 12:58:11 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GHOST_INTERNAL_H
# define GHOST_INTERNAL_H

# include "enemy.h"

typedef struct s_ghost_step
{
	t_game	*g;
	t_pos	*moved;
	int		moved_count;
}			t_ghost_step;

typedef struct s_ghost_best
{
	int		best_x;
	int		best_y;
	int		best_d;
}			t_ghost_best;

int			ghost_can_enter(t_game *g, int x, int y);
int			ghost_is_occupied(t_ghost_step *st, int x, int y);
int			ghost_dist(t_game *g, int x, int y);

void	ghost_choose_step(t_ghost_step *st, t_pos *gh, int *out_x, int *out_y);

#endif