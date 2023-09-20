#include "../inc/minishell.h"

// NOT WORKING WHEN echo "\\" nos scaping double nackslash

int	ft_has_valid_quotes(char *str) 
{
	int i;
	int simple_q;
	int	double_q;
	
	i = -1;
	simple_q = 0;
	double_q = 0;

	if (ft_strlen(str) == 0)
		return (1);
	while (str[++i])
	{
		if ((double_q % 2 == 0 || (double_q == 0 && simple_q != 0)) && (str[i] == '\'') && (str[i - 1] != '\\'))
			simple_q++;
		else if ((simple_q % 2 == 0 || (simple_q == 0 && double_q != 0)) && str[i] == '\"' && str[i - 1] != '\\')
			double_q++;
	}
	if (simple_q % 2 == 0 && double_q == 0)
		return (1);
	if (double_q % 2 == 0 && simple_q == 0)
		return (1);
	else
		return 0;
}