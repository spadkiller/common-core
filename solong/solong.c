/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:44:26 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/26 19:15:56 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "map_checker/map_checker.h"
#include "libft/libft.h"


int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (ft_putstr_fd("Usage: ./so_long map.ber\n", 2), 1);
	if (map_check(&map, argv[1]) != 0)
		return (ft_putstr_fd("Error\nInvalid map\n", 2), 1);
	ft_putstr_fd("OK\n", 1);
	map_free(&map);
	return (0);
}