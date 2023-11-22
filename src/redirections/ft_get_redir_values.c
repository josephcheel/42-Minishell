/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redir_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:02:47 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/21 04:01:50 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_redir_add_list(char *filename, t_list **head)
{
	t_list	*temp;

	temp = ft_lstnew((char *)filename);
	if (!temp)
		return ;
	ft_lstadd_back(head, temp);
}

static void	get_values_loop(char *raw_cmd, int i, t_minishell *data,
	t_quote quotes)
{
	while (raw_cmd[++i])
	{
		ft_get_quotes_values(raw_cmd[i], &quotes);
		if (raw_cmd[i] == '<' && raw_cmd[i + 1] != '<'
			&& !quotes.dbl && !quotes.simple)
			ft_get_value_infile(data, &raw_cmd[i]);
		else if (raw_cmd[i] == '<' && raw_cmd[i + 1] == '<'
			&& !quotes.dbl && !quotes.simple)
		{
			i += 1;
			ft_get_value_heredoc(data, &raw_cmd[i]);
		}
		else if (raw_cmd[i] == '>' && raw_cmd[i + 1] != '>'
			&& !quotes.dbl && !quotes.simple)
			ft_get_value_outfile(data, &raw_cmd[i]);
		else if (raw_cmd[i] == '>' && raw_cmd[i + 1] == '>'
			&& !quotes.dbl && !quotes.simple)
		{
			i += 1;
			ft_get_value_append(data, &raw_cmd[i]);
		}
	}
}

void	ft_get_redit_value(char *raw_cmd, t_minishell *data)
{
	int		i;
	t_quote	quotes;

	i = -1;
	quotes.dbl = 0;
	quotes.simple = 0;
	get_values_loop(raw_cmd, i, data, quotes);
}

// int main(void)
// {
// 	t_minishell *data;
// 	data->out_files = NULL;
// 	data->in_files = NULL;
// 	// data->heredoc = NULL;
// 	char *str = ft_strdup("echo > \"outfile\" < inf
//ile >> doubleoutfile    <<END ");
// 	ft_get_redit_value(str, data);
// 	if (data->heredoc)
// 		printf("%s\n", data->heredoc);
// 	t_list *temp;
// 	temp = data->in_files;
// 	while (temp)
// 	{
// 		printf("shjfjsaf %s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// }
