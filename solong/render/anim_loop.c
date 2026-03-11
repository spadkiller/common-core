/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:01:54 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/11 11:02:41 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all.h"
#include "render.h"

int	anim_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	g->tick++;
	if (g->tick % 10 == 0)
	{
		g->anim_frame ^= 1;
		draw_map(g);
	}
	return (0);
}
