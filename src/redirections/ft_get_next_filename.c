#include "../../inc/minishell.h"

char *ft_get_next_filename(char *raw_cmd)
{
	int i;
	char **split;
	char *filename;


	i = 0;
	while (raw_cmd[i])
	{
		while (raw_cmd[i] == '<' | raw_cmd[i] == '>')
			i++;
		while (ft_isspace(raw_cmd[i]))
			i++;
		split = ft_split_quotes(&raw_cmd[i]);
		filename = ft_strdup(split[0]);
		ft_array_free(split, ft_array_size(split));
	}
	return (filename);
}