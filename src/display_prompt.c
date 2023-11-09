#include "../inc/minishell.h"

#define GREEN "\x1b[32;01m"
#define RESET_COLOR "\x1b[0m"
char	*display_prompt_msg(void)
{
	char	*line;

	// line = readline(GREEN "42-Minishell ~ % " RESET_COLOR);
	line = readline("42-Minishell ~ % ");
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
