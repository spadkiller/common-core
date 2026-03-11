/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:03:14 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/09 16:17:43 by gujarry          ###   ########.fr       */
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
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	is_blank(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static void	cmd_not_found(void)
{
	write(2, "Command not found\n", 18);
	exit(127);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	*argv_exec[4];

	if (is_blank(cmd))
		cmd_not_found();
	if (path_missing(envp) && !has_slash(cmd))
		cmd_not_found();
	argv_exec[0] = "bash";
	argv_exec[1] = "-c";
	argv_exec[2] = cmd;
	argv_exec[3] = NULL;
	execve("/bin/bash", argv_exec, envp);
	argv_exec[0] = "sh";
	execve("/bin/sh", argv_exec, envp);
	error_exit("execve");
}
