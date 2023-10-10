#include "../../inc/minishell.h"

// char	*ft_replace_string(char *str, char *replace, char *replacer)
// {
// 	char *find;
// 	char *before_rp;
// 	char *after_rp;
// 	size_t before_len;
// 	size_t after_len;

// 	find = ft_strnstr(str, replace);
// 	before_len = find - str;
// 	after_len = strlen(str) - before_len - strlen(replace);

// 	before_rp = ft_substr(str, 0, find - str - 1);
// 	if (str - find + ft_strlen(replace) == 0)
// 		after_rp = ft_substr(str, str - find + ft_strlen(replace), ft_strlen(str));
// 	ft_strlcat(before_rp, replacer, ft_strlen(before_rp) + ft_strlen(replacer));
// 	if (str - find + ft_strlen(replace))
// 		ft_strlcat(before_rp, after_rp, ft_strlen(before_rp) + ft_strlen(after_rp));
// 	(void)replacer;
// 	return (after_rp);
// }