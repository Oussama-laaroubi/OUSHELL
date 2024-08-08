/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:10:08 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/08 12:20:51 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static t_env	*ft_create_node(char *env)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		exit(EXIT_FAILURE);
	new->line = env;
	new->name = ft_costume_strchr(env, '=');
	new->value = ft_strchr(env, '=');
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static t_env	*ft_add_node(t_env **head, char *env)
{
	t_env	*new;
	t_env	*temp;

	new = ft_create_node(env);
	if (!*head)
		return (new);
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	new->next = NULL;
	return (*head);
}

void    get_env(t_env **env_list, char **env)
{
    int i;
    t_env   *tmp;

    *env_list = NULL;
    i = -1;
    while(env[++i])
        *env_list = ft_add_node(env_list, env[i]);
    
    tmp = *env_list;
    printf("=== THE LINE IS ==== %s\n", tmp->line);
    printf("=== THE NAME IS ==== %s\n", tmp->name);
    printf("=== THE VALUE IS ==== %s\n", tmp->value);
}