/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:44:26 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/25 15:25:13 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static void	putstr_fd(const char *s, int fd)
{
	size_t	i = 0;
	if (!s) return;
	while (s[i]) { write(fd, &s[i], 1); i++; }
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (putstr_fd("Usage: ./so_long map.ber\n", 2), 1);
	if (map_check(&map, argv[1]) != 0)
		return (putstr_fd("Error\nInvalid map\n", 2), 1);
	putstr_fd("OK\n", 1);
	map_free(&map);
	return (0);
}