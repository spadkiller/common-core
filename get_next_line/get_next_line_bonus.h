/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:55:26 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/24 13:35:19 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	int				fd;
	char			*buffer;
	struct s_gnl	*next;
}					t_gnl;

char				*get_next_line(int fd);

size_t				ft_strlen(char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char *s1, char *s2);

t_gnl				*search_fd(t_gnl **stock, int fd);
t_gnl				*new_node(int fd);
void				free_node(t_gnl **stock, int fd);
char				*read_and_stock(int fd, char *buffer);
char				*ft_get_line(char *buffer);
char				*save_rest(char *buffer);

#endif