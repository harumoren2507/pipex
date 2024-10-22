/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:26:29 by retoriya          #+#    #+#             */
/*   Updated: 2024/10/22 19:23:29 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_getenv(char *envname, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0' && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strncmp(sub, envname, 4) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*find_executable(char **all_path, char **split_cmd)
{
	int		i;
	char	*path_part;
	char	*exec_path;

	i = 0;
	while (all_path[i] != NULL)
	{
		path_part = ft_strjoin(all_path[i], "/");
		exec_path = ft_strjoin(path_part, split_cmd[0]);
		free(path_part);
		if (access(exec_path, F_OK | X_OK) == 0)
			return (exec_path);
		free(exec_path);
		i++;
	}
	return (NULL);
}

char	*ft_getpath(char *cmd, char **env)
{
	int		i;
	char	**all_path;
	char	**split_cmd;
	char	*exec_path;

	i = 0;
	all_path = ft_split(ft_getenv("PATH", env), ':');
	split_cmd = ft_split(cmd, ' ');
	exec_path = find_executable(all_path, split_cmd);
	ft_free_tab(all_path);
	ft_free_tab(split_cmd);
	return (exec_path);
}
