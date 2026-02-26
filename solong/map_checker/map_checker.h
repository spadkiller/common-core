/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:45:38 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/26 19:18:07 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKER_H
# define MAP_CHECKER_H

# include "../all.h"
# include "../get_next_line/get_next_line.h"

int		map_load(t_map *map, const char *path);
int		map_validate(t_map *map);
int		map_check(t_map *map, const char *path);
void	map_free(t_map *map);
int		map_check_path(t_map *map);

#endif
