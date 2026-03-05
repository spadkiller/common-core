/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:57:15 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 12:14:29 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

static void	free_grid_copy(char **g)
{
	int	i;

	if (!g)
		return ;
	i = 0;
	while (g[i])
		free(g[i++]);
	free(g);
}

static char	**dup_grid(t_map *map)
{
	char	**copy;
	int		y;

	copy = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < map->height)
	{
		copy[y] = ft_strdup(map->grid[y]);
		if (!copy[y])
			return (free_grid_copy(copy), NULL);
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

static void	find_player(t_map *map, int *px, int *py)
{
	int	x;
	int	y;

	*px = -1;
	*py = -1;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == PLAYER)
			{
				*px = x;
				*py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	push_pos(t_pos *stack, int *top, int x, int y)
{
	stack[*top].x = x;
	stack[*top].y = y;
	(*top)++;
	return (0);
}

static int	flood_iter(char **g, t_map *map, int px, int py, int *c_ok, int *e_ok)
{
	t_pos	*stack;
	int		top;
	int		max;
	int		x;
	int		y;
	char	cell;

	max = map->width * map->height;
	stack = (t_pos *)malloc(sizeof(t_pos) * max);
	if (!stack)
		return (1);
	top = 0;
	push_pos(stack, &top, px, py);
	while (top > 0)
	{
		top--;
		x = stack[top].x;
		y = stack[top].y;
		if (x < 0 || y < 0 || x >= map->width || y >= map->height)
			continue ;
		cell = g[y][x];
		if (cell == WALL || cell == 'V')
			continue ;
		if (cell == COLLECTIBLE)
			(*c_ok)++;
		if (cell == EXIT)
		{
			(*e_ok)++;
			g[y][x] = 'V';
			continue ;
		}
		g[y][x] = 'V';
		push_pos(stack, &top, x + 1, y);
		push_pos(stack, &top, x - 1, y);
		push_pos(stack, &top, x, y + 1);
		push_pos(stack, &top, x, y - 1);
	}
	free(stack);
	return (0);
}

int	map_check_path(t_map *map)
{
	char	**g;
	int		px;
	int		py;
	int		c_ok;
	int		e_ok;

	if (!map || !map->grid)
		return (1);
	find_player(map, &px, &py);
	if (px < 0 || py < 0)
		return (1);
	g = dup_grid(map);
	if (!g)
		return (1);
	c_ok = 0;
	e_ok = 0;
	if (flood_iter(g, map, px, py, &c_ok, &e_ok) != 0)
		return (free_grid_copy(g), 1);
	free_grid_copy(g);
	if (c_ok != map->collec_count)
		return (1);
	if (e_ok < 1)
		return (1);
	return (0);
}
