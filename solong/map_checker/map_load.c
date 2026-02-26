/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:56:44 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/26 21:32:33 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

static void	map_init(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->player_count = 0;
	map->exit_count = 0;
	map->collec_count = 0;
}

static char	*trim_nl(char *line)
{
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

static int	grid_push(char ***grid, int *size, char *new_line)
{
	char	**new_grid;
	int		i;

	new_grid = (char **)malloc(sizeof(char *) * (*size + 2));
	if (!new_grid)
		return (free(new_line), 1);
	i = 0;
	while (i < *size)
	{
		new_grid[i] = (*grid)[i];
		i++;
	}
	new_grid[i++] = new_line;
	new_grid[i] = NULL;
	free(*grid);
	*grid = new_grid;
	(*size)++;
	return (0);
}

int	map_load(t_map *map, const char *path)
{
	int		fd;
	char	*line;
	char	*dup;
	int		h;

	if (!map || !path)
		return (1);
	map_init(map);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nopen"), 1);
	h = 0;
	line = get_next_line(fd);
	while (line)
	{
		trim_nl(line);
		if (line[0] == '\0')
			return (free(line), close(fd), map_free(map), 1);
		dup = ft_strdup(line);
		free(line);
		if (!dup)
			return (close(fd), map_free(map), 1);
		if (grid_push(&map->grid, &h, dup) != 0)
			return (close(fd), map_free(map), 1);
		line = get_next_line(fd);
	}
	close(fd);
	map->height = h;
	if (map->height == 0)
		return (map_free(map), 1);
	map->width = (int)ft_strlen(map->grid[0]);
	return (0);
}
