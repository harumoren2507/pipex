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

int	main(int argc, char *argv[], char **env)
{
	(void)argc;
	(void)argv;
	char *path = ft_getenv("PATH", env);
	int	i;

	i = 0;
	if (path)
		printf("PATH: %s\n", path);
	while (env[i] != NULL)
	{
		//printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
