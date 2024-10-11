#include "../pipex.h"

char *ft_getenv(char *envname, char **env)
{
	int	i;
	int	j;
	char *sub;
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

char *ft_getpath(char *cmd, char **env)
{
	int	i;
	i = 0;
	char *path;
	char **all_path;
	char **s_cmd;
	char *path_part;
	char *exec_path;

	path = ft_getenv("PATH", env);
	allpath = ft_split(path, ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[i] != NULL)
	{
		path_part = ft_strjoin(all_path, "/");
		exec_path = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec_path, F_OK | X_OK) == 0)
		{
			ft_free_tab(all_path);
			ft_free_tab(s_cmd);
			return (exec_path);
		}
		free(exec_path);
		i++;
	}
	ft_free_tab(all_path);
	ft_free_tab(s_cmd);
	return (cmd);
}

