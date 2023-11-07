#include "../../inc/minishell.h"

int ft_permission_files_in(t_list **head) // return (0) OK return (1) FAIL
{
	t_list *temp;

	temp = *head;
	while (temp)
	{
		if (access(temp->content, F_OK) == 0)
		{
			if (access(temp->content, W_OK) != 0)
			{
				ft_putstr_fd("bash: ", 2);
				ft_putstr_fd(temp->content, 2);
				ft_putstr_fd(": Permission denied\n", 2);
				return (1);
			}
		}
		else
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(temp->content, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (1);
		}
		temp = temp->next;
	}
	return(0);
}