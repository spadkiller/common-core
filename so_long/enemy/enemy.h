/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:53:48 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 12:59:30 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include "../all.h"

int		ghosts_collect_and_clear(t_game *g);
void	ghosts_step_towards_player(t_game *g);

#endif