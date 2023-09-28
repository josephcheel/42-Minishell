#include "../inc/minishell.h"

char	*display_prompt_msg(void)
{
	char *line;

	line = readline("\e[38;5;113m42-Minishell ~ % \e[0m"); // readline won't compile if you don't use -lreadline flag
	if (ft_strlen(line) > 0)
		add_history(line); // to add a history to shell; You can search with up and down arrow keys (↑ ↓) 
	
	return (line);
}

//history command necessary?