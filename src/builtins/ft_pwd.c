#include "../../inc/minishell.h"

int pwd_builtin(t_minishell *data)
{
	char *path;

	path = (char *)malloc(200*sizeof(char));
	getcwd(path,200);
	printf("%s\n", path);
	(void)data;
	return (1);
}
