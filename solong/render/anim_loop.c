/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:01:54 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/11 11:51:10 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all.h"
#include "render.h"


static long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 500L) + (tv.tv_usec / 500L));
}

int	anim_loop(void *param)
{
	t_game	*g;
	long	ms;

	g = (t_game *)param;
	ms = now_ms();
	if (g->last_anim_ms == 0)
		g->last_anim_ms = ms;
	if (ms - g->last_anim_ms >= 500)
	{
		g->anim_frame++;
		if (g->anim_frame >= 3)
			g->anim_frame = 0;
		g->last_anim_ms = ms;
		draw_map(g);
	}
	return (0);
}
