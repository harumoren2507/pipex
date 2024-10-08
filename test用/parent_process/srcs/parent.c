#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"

#define BUFFER_SIZE 1024

void error_message(const char *msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 3)
	{
		error_message(ERR_ARGC);
	}
	int input_fd = open(argv[1], O_RDONLY);
	if (input_fd = -1)
		error_message(ERR_PIPE);
	if (dup2(input_fd, STDIN_FILENO) == -1) {
		error_message(ERR_DUP);
	}
	close(input_fd);

	char *cmd_path = "/bin/";
	char full_path[BUFFER_SIZE];
	ft_strlcpy(full_path, cmd_path, BUFFER_SIZE);
	ft_strlcat(full_path, argv[2], BUFEER_SIZE);

	char *cmd_args[] = {argc[2], NULL};
	execve(full_path, cmd_args, envp);

	error_message(ERR_EXECVE);
	return (0);
}

