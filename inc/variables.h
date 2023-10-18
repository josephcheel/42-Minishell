#ifndef VARIABLE_H
# define VARIABLE_H

# include "environment.h"
# include "../libft/inc/libft.h"


void	ft_set_variable(t_env **head, char *id, char *value);
void	ft_add_variable(t_env **head, char *id, char *value);
char	*ft_get_variable(t_env **head, char *id);
#endif