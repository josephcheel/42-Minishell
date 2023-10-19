#include "../inc/libft.h"

int ft_isstrupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isupper(str[i]))
			return(0);
		i++;
	}
	return(1);
}