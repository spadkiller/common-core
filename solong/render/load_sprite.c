/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:55:56 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/11 11:24:42 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../libft/libft.h"

static int	load_one(t_game *g, t_img *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(g->mlx, path, &img->w, &img->h);
	if (!img->ptr)
	{
		ft_putstr_fd("Error\nFailed to load: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}

int	load_sprites(t_game *g)
{
	if (load_one(g, &g->sp.floor, "sprite/floor.xpm"))
		return (1);
	if (load_one(g, &g->sp.wall, "sprite/wall.xpm"))
		return (1);
	if (load_one(g, &g->sp.player, "sprite/player.xpm"))
		return (1);
	if (load_one(g, &g->sp.exit, "sprite/exit.xpm"))
		return (1);
	if (load_one(g, &g->sp.collect, "sprite/collect.xpm"))
		return (1);
	if (load_one(g, &g->sp.ghost, "sprite/ghost.xpm"))
		return (1);

	if (load_one(g, &g->sp.collect_anim[0], "sprite/collect.xpm"))
		return (1);
	if (load_one(g, &g->sp.collect_anim[1], "sprite/collect_rot1.xpm"))
		return (1);
	if (load_one(g, &g->sp.collect_anim[2], "sprite/collect_rot2.xpm"))
		return (1);
	return (0);
}
