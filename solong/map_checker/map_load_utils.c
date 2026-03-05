/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:24:32 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 13:25:52 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"
#include "../libft/libft.h"

void	map_init(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->player_count = 0;
	map->exit_count = 0;
	map->collec_count = 0;
	map->ghost_count = 0;
}

static char	*trim_nl(char *line)
{
	size_t	len;

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

int	map_push_line(t_map *map, char *line)
{
	char	*dup;

	trim_nl(line);
	if (line[0] == '\0')
		return (free(line), 1);
	dup = ft_strdup(line);
	free(line);
	if (!dup)
		return (1);
	if (grid_push(&map->grid, &map->height, dup) != 0)
		return (1);
	return (0);
}
