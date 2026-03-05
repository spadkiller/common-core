/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_flood.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:13:23 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 15:04:00 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

static int	can_visit(t_flood *f, int x, int y)
{
	char	cell;

	if (x < 0 || y < 0 || x >= f->map->width || y >= f->map->height)
		return (0);
	cell = f->g[y][x];
	if (cell == WALL || cell == 'V')
		return (0);
	if (cell == COLLECTIBLE)
		f->c_ok++;
	if (cell == EXIT)
	{
		f->e_ok++;
		f->g[y][x] = 'V';
		return (0);
	}
	f->g[y][x] = 'V';
	return (1);
}

static void	push(t_flood *f, int x, int y)
{
	if (f->top >= f->max)
		return ;
	f->st[f->top].x = x;
	f->st[f->top].y = y;
	f->top++;
}

static void	push_neighbors(t_flood *f, int x, int y)
{
	if (can_visit(f, x + 1, y))
		push(f, x + 1, y);
	if (can_visit(f, x - 1, y))
		push(f, x - 1, y);
	if (can_visit(f, x, y + 1))
		push(f, x, y + 1);
	if (can_visit(f, x, y - 1))
		push(f, x, y - 1);
}

static int	check_result(t_flood *f)
{
	if (f->c_ok != f->map->collec_count)
		return (1);
	if (f->e_ok < 1)
		return (1);
	return (0);
}

int	map_flood_check(char **g, t_map *map, int px, int py)
{
	t_flood	f;
	size_t	max;

	if (map->width > 200 || map->height > 200)
		return (1);
	max = (size_t)map->width * (size_t)map->height;
	f.g = g;
	f.map = map;
	f.st = (t_pos *)malloc(sizeof(t_pos) * max);
	if (!f.st)
		return (1);
	f.top = 0;
	f.max = (int)max;
	f.c_ok = 0;
	f.e_ok = 0;
	if (can_visit(&f, px, py))
		push(&f, px, py);
	while (f.top > 0)
	{
		f.top--;
		push_neighbors(&f, f.st[f.top].x, f.st[f.top].y);
	}
	free(f.st);
	return (check_result(&f));
}
