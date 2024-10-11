#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../pipex.h"

void error_message(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	proto_execve(char *commond, char **envp)
{
	char *cmd_path = "/bin/";
	char full_path[BUFFER_SIZE];
	ft_strlcpy(full_path, cmd_path, BUFFER_SIZE);
	ft_strlcat(full_path, commond, BUFFER_SIZE);
	char *cmd_args[] = {commond, NULL};
	execve(full_path, cmd_args, envp);
	error_message(ERR_EXECVE);
}

void	ft_child(char *argv[], int *pipe_fd, char **envp)
{
	int	input_fd;
	input_fd = open(argv[1], O_RDONLY);
	dup2(input_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	proto_execve(argv[2], envp);
}

void	ft_parent(char *argv[], int *pipe_fd, char **envp)
{
	int output_fd;

	output_fd = open(argv[4], O_WRONLY);
	dup2(output_fd, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	proto_execve(argv[3], envp);
}
int	main(int argc, char *argv[], char **envp)
{
	int	pipe_fd[2];
	pid_t pid;

	if (argc != 5)
		error_message(ERR_ARGC);
	if (pipe(pipe_fd) == -1)
		error_message(ERR_PIPE);
	pid = fork();
	if (pid == 0)
		ft_child(argv, pipe_fd, envp);
	ft_parent(argv, pipe_fd, envp);
	return (0);
}


