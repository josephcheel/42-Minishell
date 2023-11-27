/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:59:16 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/25 23:17:18 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <stdio.h>
# include "../libft/inc/libft.h"

typedef struct s_env
{
	char			*id;
	char			*value;
	struct s_env	*next;
}t_env;

void	ft_printlist(t_env *head, char *id);
void	ft_printlist_id(t_env *head, char *id);
void	ft_printlist_value(t_env *head, char *id);

t_env	*ft_create_new_node(char *id, char *value);
t_env	*ft_insert_at_head(t_env **head, t_env *node_to_insert);
t_env	*ft_insert_at_end(t_env **head, t_env *node_to_insert);
void	ft_insert_after_node(t_env *node_to_insert_after, t_env *newnode);
t_env	*ft_find_id(t_env *head, char *id);
t_env	*ft_find_value(t_env *head, char *value);
int		ft_listsize(t_env *head);

char	**ft_env_to_array(t_env *head);
void	ft_free_env(t_env *head);


t_env	*ft_envlast(t_env *lst);
void	ft_envadd_back(t_env **lst, t_env *new);
t_env	*ft_envnew(char *id, char *value);
#endif