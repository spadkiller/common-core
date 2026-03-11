/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:05:23 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/09 16:17:23 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include "pipex.h"

int	path_missing(char **envp)
{
	int	i;

	if (!envp)
		return (1);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i][5] == '\0');
		i++;
	}
	return (1);
}

int	has_slash(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
