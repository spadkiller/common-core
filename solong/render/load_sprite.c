/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:55:56 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/26 21:25:16 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all.h"

static int	load_one(t_game *g, t_img *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(g->mlx, path, &img->w, &img->h);
	if (!img->ptr)
		return (1);
	return (0);
}

int	load_sprites(t_game *g)
{
	if (load_one(g, &g->sp.floor, "solong/sprite/floor.xpm"))
		return (1);
	if (load_one(g, &g->sp.wall, "solong/sprite/wall.xpm"))
		return (1);
	if (load_one(g, &g->sp.player, "solong/sprite/player.xpm"))
		return (1);
	if (load_one(g, &g->sp.exit, "solong/sprite/exit.xpm"))
		return (1);
	if (load_one(g, &g->sp.collect, "solong/sprite/collect.xpm"))
		return (1);
	return (0);
}