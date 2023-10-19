#include "../inc/libft.h"

int	ft_isstralnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]))
			return 1;
		i++;
	}
	return (0);
}