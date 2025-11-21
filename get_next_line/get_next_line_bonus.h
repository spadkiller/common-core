/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:55:26 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/21 16:21:25 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

#include <stddef.h>
#include <unistd.h>

typedef struct s_gnl
{
	int			fd;
    char       *buffer;
	struct s_gnl	*next;
}t_gnl;

size_t	ft_strlen(char *str);


#endif