/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:59:21 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/25 14:53:48 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all.h"

static void	destroy_one(t_game *g, t_img *img)
{
	if (img->ptr)
		mlx_destroy_image(g->mlx, img->ptr);
	img->ptr = NULL;
}

void	destroy_sprites(t_game *g)
{
	int	i;

	destroy_one(g, &g->sp.floor);
	destroy_one(g, &g->sp.wall);
	destroy_one(g, &g->sp.player);
	destroy_one(g, &g->sp.exit);
	destroy_one(g, &g->sp.collect);
	destroy_one(g, &g->sp.ghost);
	i = 0;
	while (i < 3)
	{
		destroy_one(g, &g->sp.collect_anim[i]);
		i++;
	}
}
