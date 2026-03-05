/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:56:44 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 13:25:19 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

static int	open_map(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		perror("Error\nopen");
	return (fd);
}

static int	load_lines(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (map_push_line(map, line) != 0)
			return (1);
		line = get_next_line(fd);
	}
	return (0);
}

int	map_load(t_map *map, const char *path)
{
	int	fd;

	if (!map || !path)
		return (1);
	map_init(map);
	fd = open_map(path);
	if (fd < 0)
		return (1);
	if (load_lines(map, fd) != 0)
		return (close(fd), map_free(map), 1);
	close(fd);
	if (map->height == 0)
		return (map_free(map), 1);
	map->width = (int)ft_strlen(map->grid[0]);
	return (0);
}
