#include "../inc/libft.h"

char *ft_strlwr(char *str)
{
	int i;

	i = -1;
	if (!str)
		return (NULL);
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}