#include "../includes/pipex.h"
void	perror_message(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	print_file_not_found(const char *filename)
{
	ft_putstr_fd("zsh: no such file or directory: ", 2);
	ft_putendl_fd(filename, 2);
	exit(EXIT_FAILURE);
}

