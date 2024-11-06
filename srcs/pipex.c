/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:26:15 by retoriya          #+#    #+#             */
/*   Updated: 2024/11/06 20:58:54 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	execute(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	path = ft_getpath(split_cmd[0], env);
	if (execve(path, split_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: commond not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		ft_free_tab(split_cmd);
		exit(0);
	}
}

void	child_process(char *argv[], int *pipe_fd, char **envp)
{
	int	input_fd;

	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		print_file_not_found(argv[1]);
	dup2(input_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char *argv[], int *pipe_fd, char **envp)
{
	int	output_fd;

	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(output_fd, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char *argv[], char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		status;

	if (argc != 5)
		perror_message(ERR_ARGC);
	if (pipe(pipe_fd) == -1)
		perror_message(ERR_PIPE);
	pid = fork();
	if (pid == 0)
		child_process(argv, pipe_fd, envp);
	else
	{
		waitpid(pid, &status, 0);
		 if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        		exit(1);
		parent_process(argv, pipe_fd, envp);
	}
}

