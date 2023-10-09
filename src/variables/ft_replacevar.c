#include "../../inc/minishell.h"

char	*ft_replace_string(char *str, char *replace, char *replacer)
{
	char *find;
	char *before_rp;
	char *after_rp;

	after_rp = NULL; // correction because no compiling

	
	find = ft_strchr(str, '$');
	before_rp = ft_substr(str, 0, find - str - 1);
	if (str - find + ft_strlen(replace) == 0)
		after_rp = ft_substr(str, str - find + ft_strlen(replace), ft_strlen(str));
	ft_strlcat(before_rp, replacer, ft_strlen(before_rp) + ft_strlen(replacer));
	if (str - find + ft_strlen(replace))
		ft_strlcat(before_rp, after_rp, ft_strlen(before_rp) + ft_strlen(after_rp));
	(void)replacer;
	return (after_rp);
}