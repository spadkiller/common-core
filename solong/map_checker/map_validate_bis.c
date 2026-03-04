/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:17:54 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/04 17:29:30 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

static int	is_valid_char(char c)
{
	return (c == WALL || c == EMPTY || c == PLAYER
		|| c == EXIT || c == COLLECTIBLE || c == GHOST);
}