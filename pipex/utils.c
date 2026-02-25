/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:03:14 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/11 23:12:40 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args)
		error_exit("split");
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		free_tab(args);
		write(2, "command not found\n", 18);
		exit(127);
	}
	execve(path, args, envp);
	free_tab(args);
	free(path);
	error_exit("execve");
}
//ajouter 126 si j'ai pas less autorisation d'exce
