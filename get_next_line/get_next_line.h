/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:16:51 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/20 14:35:06 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(const char *str, char c);
size_t				ft_strlen(char *str);
char				*save_rest(char *stock);
char				*ft_get_line(char *stock);
char				*read_and_stock(int fd, char *stock);

#endif