/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:44:04 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/09 16:14:10 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_children(pid_t pid1, pid_t pid2)
{
	int		status;
	int		status2;
	pid_t	pid;
	int		i;

	(void)pid1;
	status2 = 1;
	i = 0;
	while (i < 2)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == pid2)
			status2 = status;
		i++;
	}
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	if (WIFSIGNALED(status2))
		return (128 + WTERMSIG(status2));
	return (1);
}
