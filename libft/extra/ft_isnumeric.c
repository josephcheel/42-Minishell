#include "../inc/libft.h"

int	ft_isnumeric(char *str)
{
	int i;

	i = 0;
    if (str == NULL || *str == '\0')
        return 0;
	str = ft_strtrim(str, " ");
	if (str[0] == '-' || str[0] == '+')
		str++;
	if (str == NULL || *str == '\0')
        return 0;
	while (str[i] != '\0')
	{
        if (!ft_isdigit(str[i]))
            return 0;
        i++;     
    }
    return 1; // All characters are numeric
}
