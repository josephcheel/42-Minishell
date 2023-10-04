#include "../inc/libft.h"

char *ft_strlwr(char *str)
{
	int		i;
	char	*new_str;

	new_str = ft_strdup(str);
	i = -1;
	if (!str || !new_str)
		return (NULL);
	while (str[++i])
		new_str[i] = ft_tolower(str[i]);
	return (new_str);
}