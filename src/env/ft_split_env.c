#include "../../inc/minishell.h"

char **ft_split_env(char *line)
{
	int find;
	char **split;

	find = 0;
	while (line[find])
	{
		if (line[find] == '=')
			break ;
		find++;
	}
	split = malloc(sizeof(char *) * (3));
	split[0] = ft_substr(line, 0, find);
	split[1] = ft_substr(line, find + 1, ft_strlen(line));
	split[2] = NULL;
	return (split);
}