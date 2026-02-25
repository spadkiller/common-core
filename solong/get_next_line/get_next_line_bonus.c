/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:55:05 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/24 13:33:12 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*read_and_stock(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	ret;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	ret = 1;
	while (ret > 0 && !ft_strchr(buffer, '\n'))
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		if (ret == -1)
			return (free(tmp), free(buffer), NULL);
		if (ret == 0)
			break ;
		tmp[ret] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (!buffer)
			return (free(tmp), NULL);
	}
	free(tmp);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*save_rest(char *buffer)
{
	char	*rest;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	rest = malloc(ft_strlen(buffer) - i);
	if (!rest)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		rest[j++] = buffer[i++];
	rest[j] = '\0';
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static t_gnl	*stock = NULL;
	t_gnl			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = search_fd(&stock, fd);
	if (!node)
		return (NULL);
	node->buffer = read_and_stock(fd, node->buffer);
	if (!node->buffer)
	{
		free_node(&stock, fd);
		return (NULL);
	}
	line = ft_get_line(node->buffer);
	node->buffer = save_rest(node->buffer);
	if (!node->buffer)
		free_node(&stock, fd);
	return (line);
}
