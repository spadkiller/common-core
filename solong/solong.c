/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:44:26 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/26 20:12:28 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "libft/libft.h"

int	start_game(const char *map_path);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr_fd("Usage: ./so_long map.ber\n", 2), 1);
	return (start_game(argv[1]));
}