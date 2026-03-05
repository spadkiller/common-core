/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:45:16 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 15:22:20 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"
#include "../libft/libft.h"

static int	is_dot_ber(const char *path)
{
	size_t	i;

	i = ft_strlen(path);
	if (i < 4)
		return (1);
	if (i >= 5 && path[i - 5] == '/' && path[i - 4] == '.'
		&& path[i - 3] == 'b' && path[i - 2] == 'e' && path[i - 1] == 'r')
		return (1);
	return (0);
}

static int	has_ber_extension(const char *path)
{
	size_t	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 4)
		return (0);
	if (path[len - 4] != '.')
		return (0);
	if (path[len - 3] != 'b')
		return (0);
	if (path[len - 2] != 'e')
		return (0);
	if (path[len - 1] != 'r')
		return (0);
	return (1);
}

int	map_check(t_map *map, const char *path)
{
	if (!has_ber_extension(path))
		return (1);
	if (map_load(map, path) != 0)
		return (1);
	if (map_validate(map) != 0)
		return (map_free(map), 1);
	if (map_check_path(map) != 0)
		return (map_free(map), 1);
	if (is_dot_ber(path))
		return (1);
	return (0);
}
