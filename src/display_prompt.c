#include "../inc/minishell.h"

char	*display_prompt_msg(void)
{
	char	*line;

	line = readline("42-Minishell ~ % ");
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
