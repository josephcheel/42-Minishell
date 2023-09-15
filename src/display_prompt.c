#include "../inc/minishell.h"

//OPTION 1 SHELL PROMPT
char	*display_prompt_msg(void)
{
	char *line;

	line = readline("42-Minishell ~ % "); // readline won't compile if you don't use -lreadline flag
	if (ft_strlen(line) > 0)
		add_history(line); // to add a history to shell; You can search with up and down arrow keys (↑ ↓) 
	
	return (line);
}

// //OPTION 2 SHELL PROMPT
// char	*display_prompt_msg(void)
// {
// 	char *line;
	
// 	char *ret;
// 	char s[100];
// 	char *prompt;
	
// 	prompt = " 42-Minishell ~ %  ";
// 	ret = getcwd(s, 100);
// 	ft_strlcat(ret, prompt, ft_strlen(prompt) + ft_strlen(ret));
// 	line = readline(ret);  // readline won't compile if you don't use -lreadline flag
// 	if (ft_strlen(line) > 0)
// 		add_history(line); // to add a history to shell; You can search with up and down arrow keys (↑ ↓) 
	
// 	return (line);
// }