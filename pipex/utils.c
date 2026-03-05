/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:03:14 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/05 15:58:20 by gujarry          ###   ########.fr       */
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

static void	cmd_error(char *cmd, char *msg, int code)
{
	write(2, "pipex: ", 7);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(code);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		cmd_error(cmd, "command not found", 127);
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		free_tab(args);
		cmd_error(args[0], "command not found", 127);
	}
	execve(path, args, envp);
	free(path);
	free_tab(args);
	if (errno == EACCES)
		cmd_error(cmd, "Permission denied", 126);
	if (errno == ENOENT)
		cmd_error(cmd, "No such file or directory", 127);
	cmd_error(cmd, strerror(errno), 126);
}
