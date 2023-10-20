/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:08:02 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 13:08:03 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

# include "environment.h"
# include "../libft/inc/libft.h"

void	ft_set_variable(t_env **head, char *id, char *value);
void	ft_add_variable(t_env **head, char *id, char *value);
char	*ft_get_variable(t_env **head, char *id);
int		ft_check_var_rules(char *var);

#endif