/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:20:51 by retoriya          #+#    #+#             */
/*   Updated: 2024/11/06 21:55:00 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*--------------------Library--------------------*/

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/*--------------------Macro--------------------*/

# define ERR_ARGC "Invaild number of Arguments"
# define ERR_PIPE "Failed to open pipe"
# define ERR_FORK "Failed to forking"
# define ERR_CMD "Commond not found"
# define ERR_DUP "Error: dup2 failed"
# define ERR_EXECVE "Error: Command execution failed"
# define ERR_OPEN "Error:"
# define BUFFER_SIZE 1024
/*--------------------Struct--------------------*/

/*----------------proto_function----------------*/

void	ft_free_tab(char **tab);
char	*ft_getpath(char *cmd, char **env);
void	perror_message(const char *str);
void	print_file_not_found(const char *filename);

#endif
