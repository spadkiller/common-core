/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:45:16 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 12:11:33 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

static int	has_ber_extension(const char *path)
{
	size_t	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 4)
		return (0);
	return (path[len - 4] == '.' && path[len - 3] == 'b'
		&& path[len - 2] == 'e' && path[len - 1] == 'r');
}
int	map_check(t_map *map, const char *path)
{
	if (map_load(map, path) != 0)
		return (1);
	if (map_validate(map) != 0)
		return (map_free(map), 1);
	if (!has_ber_extension(path))
		return (1);
	if (map_check_path(map) != 0)
		return (map_free(map), 1);
	return (0);
}
