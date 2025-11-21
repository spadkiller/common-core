/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:10:53 by gujarry           #+#    #+#             */
/*   Updated: 2025/11/21 13:11:56 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stock(int fd, char *stock)
{
	char	*buffer;
	int		byte_read;

	byte_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!stock)
		return (NULL);
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, (BUFFER_SIZE));
		if (byte_read == -1)
			return (free(buffer),free(stock),NULL);
		if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		stock = ft_strjoin(stock, buffer);
		if (ft_strchr(stock, '\n'))
			break;
	}
	return (free(buffer), stock);
}

char	*ft_get_line(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (stock[++i] && stock[i] != '\n')
		line[i] = stock[i];
	if (stock[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save_rest(char *stock)
{
	char	*new_stock;
	int		i;
	int		j;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	new_stock = malloc(sizeof(char) * ft_strlen(stock) - i + 1);
	if (!new_stock)
		return (NULL);
	i++;
	j = 0;
	while (stock[i])
		new_stock[j++] = stock[i++];
	new_stock[j] = '\0';
	free(stock);
	return (new_stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_and_stock(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_get_line(stock);
	stock = save_rest(stock);
	return (line);
}
