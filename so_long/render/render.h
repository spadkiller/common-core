/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:30:58 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/11 11:03:03 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../all.h"

int		load_sprites(t_game *g);
void	draw_map(t_game *g);
void	destroy_sprites(t_game *g);
int		anim_loop(void *param);

#endif