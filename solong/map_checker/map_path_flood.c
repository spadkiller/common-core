/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_flood.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:13:23 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 13:18:56 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"

static void	push(t_flood *f, int x, int y)
{
	f->stack[f->top].x = x;
	f->stack[f->top].y = y;
	f->top++;
}

static void	mark_and_push(t_flood *f, int x, int y)
{
	f->g[y][x] = 'V';
	push(f, x + 1, y);
	push(f, x - 1, y);
	push(f, x, y + 1);
	push(f, x, y - 1);
}

static void	visit(t_flood *f, int x, int y)
{
	char	cell;

	if (x < 0 || y < 0 || x >= f->map->width || y >= f->map->height)
		return ;
	cell = f->g[y][x];
	if (cell == WALL || cell == 'V')
		return ;
	if (cell == COLLECTIBLE)
		f->c_ok++;
	if (cell == EXIT)
	{
		f->e_ok++;
		f->g[y][x] = 'V';
		return ;
	}
	mark_and_push(f, x, y);
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
	int		max;

	max = map->width * map->height;
	f.g = g;
	f.map = map;
	f.stack = (t_pos *)malloc(sizeof(t_pos) * max);
	if (!f.stack)
		return (1);
	f.top = 0;
	f.c_ok = 0;
	f.e_ok = 0;
	push(&f, px, py);
	while (f.top > 0)
	{
		f.top--;
		visit(&f, f.stack[f.top].x, f.stack[f.top].y);
	}
	free(f.stack);
	return (check_result(&f));
}
