#include "../../inc/minishell.h"

char	*ft_replace_string(char *str, char *replace, char *replacer)
{
	char *result;
	char *find;
	
	find = ft_strchr(str, '$');

	size_t before_len = find - str;
    size_t after_len = ft_strlen(find + ft_strlen(replace));

    char *before_rp = ft_substr(str, 0, before_len);
    char *after_rp = ft_substr(str, before_len + ft_strlen(replace) + 1, after_len);

	// printf("before $%s$\n", before_rp);
	// printf("after $%s$\n", after_rp);
	char *new_str;

	new_str = NULL;
	if (ft_strlen(replacer))
	{
		new_str = ft_strjoin(before_rp, replacer);
		result = ft_strjoin(new_str, after_rp);
		free(new_str);
	}
	else
	{
		if (ft_strlen(after_rp))
		{
   			result = ft_strjoin(before_rp, after_rp);
			return (result);
			// printf("RES %s\n", result);
		}
		else
		{
			// printf("before $%s$\n", before_rp);
			// printf("2\n");
			// return (NULL);
			return(before_rp);
		}
	}
	// free(before_rp);
    // free(after_rp);

	return (result);
}