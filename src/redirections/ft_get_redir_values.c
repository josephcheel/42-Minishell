#include "../../inc/minishell.h"


void	ft_redir_value(char *filename, t_list **head)
{
	t_list *temp;

	temp = ft_lstnew((char *)filename);
	if (!temp)
		return ;
	ft_lstadd_back(head, temp);
}


static int	ft_move_next_redir(char *raw_cmd)
{
	int i;

	i = 0;
	while ((raw_cmd[i] == '<' || raw_cmd[i] == '>' )&& raw_cmd[i])
		i++;
	while (raw_cmd[i] == ' ' && raw_cmd[i])
		i++;
	while (!ft_isspace(raw_cmd[i]) && raw_cmd[i])
		i++;
	return (i);
}

char *ft_get_redit_value(char *raw_cmd, t_minishell *data)
{
	int i;
	char *filename = NULL;
	int		d_quotes;
	int		s_quotes;

	d_quotes = 0;
	s_quotes = 0;
	i = 0;
	while (raw_cmd[i])
	{
		if (!&raw_cmd[i])
			break ;
		if (raw_cmd[i] == '\"' && !s_quotes)
			d_quotes++;
		if (raw_cmd[i] == '\'' && !d_quotes)
			s_quotes++;
		if (raw_cmd[i] == '\"' && d_quotes == 2)
			d_quotes = 0;
		if (raw_cmd[i] == '\'' && s_quotes == 2)
			s_quotes = 0;

		if (raw_cmd[i] == '<' && raw_cmd[i+1] != '<' && !d_quotes && !s_quotes) // < exists and can reads
		{
			filename = ft_get_next_filename(&raw_cmd[i]);	
			if (filename)
			{
				ft_redir_value(filename, &data->in_files);
				data->infile = filename;
				data->is_out_heredoc = 0;
			}
		}
		else if (raw_cmd[i] == '<' &&  raw_cmd[i+1] == '<' && !d_quotes && !s_quotes) // <<
		{
			i += 1;
			filename = ft_get_next_filename(&raw_cmd[i]);
			i += ft_move_next_redir(&raw_cmd[i]);
			if (filename)
			{
				ft_redir_value(filename, &data->heredocs);
				data->infile = HEREDOC_FILE;
				data->heredoc = filename;
				data->is_heredoc = 1;
				data->is_out_heredoc = 1;
			}
		}
		else if (raw_cmd[i] == '>' &&  raw_cmd[i+1] != '>' && !d_quotes && !s_quotes) // >
		{
			filename = ft_get_next_filename(&raw_cmd[i]);		
			if (filename)
			{
				ft_redir_value(filename, &data->out_files);
				data->outfile = filename;
				data->is_append = 0;
			}
		}
		else if (raw_cmd[i] == '>' &&  raw_cmd[i+1] == '>' && !d_quotes && !s_quotes) // >> 
		{
			i += 1;
			filename = ft_get_next_filename(&raw_cmd[i]);
			if (filename)
			{
				ft_redir_value(filename, &data->out_append);
				data->outfile = filename;
				data->is_append = 1;
			}
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	t_minishell *data;
// 	data->out_files = NULL;
// 	data->in_files = NULL;
// 	// data->heredoc = NULL;
// 	char *str = ft_strdup("echo > \"outfile\" < infile >> doubleoutfile    <<END ");
	
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
