/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:41:23 by gujarry           #+#    #+#             */
/*   Updated: 2026/03/14 03:24:56 by gujarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1(int infile, int fd[2], char *cmd, char **envp)
{
	if (dup2(infile, STDIN_FILENO) < 0)
		error_exit("dup2");
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		error_exit("dup2");
	close(fd[0]);
	close(fd[1]);
	close(infile);
	exec_cmd(cmd, envp);
}

static void	child2(int outfile, int fd[2], char *cmd, char **envp)
{
	if (dup2(fd[0], STDIN_FILENO) < 0)
		error_exit("dup2");
	if (dup2(outfile, STDOUT_FILENO) < 0)
		error_exit("dup2");
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	exec_cmd(cmd, envp);
}

static int	open_files(char **argv, int *infile, int *outfile)
{
	int	out_failed;

	out_failed = 0;
	*outfile = open(argv[4],  O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*outfile < 0)
	{
		out_failed = 1;
		perror(argv[4]);
		*outfile = open("/dev/null", O_WRONLY);
		if (*outfile < 0)
			exit(EXIT_FAILURE);
	}
	*infile = open(argv[1], O_RDONLY);
	if (*infile < 0)
	{
		perror(argv[1]);
		*infile = open("/dev/null", O_RDONLY);
		if (*infile < 0)
			exit(EXIT_FAILURE);
	}
	return (out_failed);
}

static int	spawn_and_wait(int infile, int outfile, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) < 0)
		error_exit("pipe");
	pid1 = fork();
	if (pid1 < 0)
		error_exit("fork");
	if (pid1 == 0)
		child1(infile, fd, argv[2], envp);
	pid2 = fork();
	if (pid2 < 0)
		error_exit("fork");  
	if (pid2 == 0)
		child2(outfile, fd, argv[3], envp);
	close(fd[0]);
	close(fd[1]);
	return (wait_children(pid1, pid2));
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
	int	status;
	int	out_failed;

	if (argc != 5)
		error_exit("Usage: ./pipex infile cmd1 cmd2 outfile");
	out_failed = open_files(argv, &infile, &outfile);
	status = spawn_and_wait(infile, outfile, argv, envp);
	close(infile);
	close(outfile);
	if (out_failed)
		return (1);
	return (status);
}
