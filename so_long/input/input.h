/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:31:26 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 13:30:33 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "../printf/ft_printf.h"
# include "../render/render.h"
# include "input.h"

int		handle_key(int keycode, t_game *g);
int		count_collect_left(t_game *g);
int		is_ghost_at(t_game *g, int x, int y);
void	game_over(t_game *g);
int		can_enter_cell(t_game *g, int nx, int ny);

#endif