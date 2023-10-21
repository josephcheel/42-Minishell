#include "../inc/minishell.h"

char	*display_prompt_msg(void)
{
	char	*line;

	line = readline("\e[38;5;113m42-Minishell ~ % \e[0m");
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
