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
