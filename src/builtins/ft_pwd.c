#include "../../inc/minishell.h"

int ft_pwd(char **cmd)
{
	char *path;

	if (ft_isstrupper(cmd[0]) && ft_array_size(cmd) > 1)
	{
		ft_putstr_fd("usage: pwd [-L | -P]\n", 2);
		return (1);
	}
	path = (char *)malloc(200*sizeof(char));
	getcwd(path,200);
	printf("%s\n", path);
	return (1);
}
