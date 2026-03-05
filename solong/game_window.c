/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:52:31 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 14:52:42 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	window_too_big(t_game *g)
{
	int	sw;
	int	sh;
	int	ww;
	int	wh;

	if (!g || !g->mlx)
		return (1);
	mlx_get_screen_size(g->mlx, &sw, &sh);
	ww = g->map.width * g->tile;
	wh = g->map.height * g->tile;
	if (ww > sw - 100)
		return (1);
	if (wh > sh - 100)
		return (1);
	return (0);
}