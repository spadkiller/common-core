/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:41:23 by gujarry           #+#    #+#             */
/*   Updated: 2026/02/10 12:20:22 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error_exit("Usage: ./pipex infile cmd1 cmd2 outfile");
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_exit("infile");
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_exit("outfile");
	if (pipe(fd) < 0)
		error_exit("pipe");
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(infile);
		exec_cmd(argv[2], envp);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(outfile);
		exec_cmd(argv[3], envp);
	}
	close(fd[0]);
	close(fd[1]);
	close(infile);
	close(outfile);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
