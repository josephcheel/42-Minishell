#include "../../inc/minishell.h"


void	ft_redir_value(char *filename, t_list *head)
{
	t_list *temp;
	
	// if (!head)
	// 	*head = ft_lstnew(filename);
	// else
	// {
		temp = ft_lstnew(filename);
		ft_lstadd_front(&head, temp);
		// ft_lstadd_back(&head, temp);
	// }
}


static int	ft_move_next_redir(char *raw_cmd)
{
	int i;

	i = 0;
	while (raw_cmd[i] == '<' || raw_cmd[i] == '>' && raw_cmd[i])
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

	i = 0;
	while (raw_cmd[i])
	{
		if (!&raw_cmd[i])
			break ;

		if (raw_cmd[i] == '<' && raw_cmd[i+1] != '<') // < exists and can reads
		{
			filename = ft_get_next_filename(&raw_cmd[i]);
			
			printf("IN > $%s$\n", filename);
			
			// i += ft_move_next_redir(&raw_cmd[i]);		
			if (filename)
				ft_redir_value(filename, data->in_files);
		}
		else if (raw_cmd[i] == '<' &&  raw_cmd[i+1] == '<') // <<
		{
			i += 1;
			printf("HEREDOC << $%s$\n", filename);
			i += ft_move_next_redir(&raw_cmd[i]);
			printf("FINAL %s\n", &raw_cmd[i]);
		}
		else if (raw_cmd[i] == '>' &&  raw_cmd[i+1] != '>' ) // >
		{
			filename = ft_get_next_filename(&raw_cmd[i]);
			printf("OUT > $%s$\n", filename);
			// i += ft_move_next_redir(&raw_cmd[i]);
			
			if (filename)
				ft_redir_value(filename, data->out_files);
		}
		else if (raw_cmd[i] == '>' &&  raw_cmd[i+1] == '>') // >> 
		{
			i += 1;
			filename = ft_get_next_filename(&raw_cmd[i]);
			printf("OUTOUT > $%s$\n", filename);
			// i += ft_move_next_redir(&raw_cmd[i]);
			if (filename)
				ft_redir_value(filename, data->out_files);
		}
		// if (!&raw_cmd[i])
		//  break ;
		// printf("AQUI %s\n", &raw_cmd[i]);
		// if (!ft_strchr(&raw_cmd[i], '<') && !ft_strchr(&raw_cmd[i], '>'))
		// 	break ;
		i++;
	}
	return (NULL);
}

int main(void)
{
	t_minishell *data;
	// data->out_files = NULL;
	// data->in_files = NULL;
	char *str = ft_strdup("echo > \"outfile\" < infile >> doubleoutfile ");
	
	ft_get_redit_value(str, data);
	// return 0;
	t_list *temp;
	
	temp = data->in_files;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}
