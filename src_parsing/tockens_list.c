/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tockens_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:55:39 by olaaroub          #+#    #+#             */
/*   Updated: 2024/09/08 20:42:53 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static t_tockens	*ft_create_node(char *word, int type)
{
	t_tockens	*new;

	new = (t_tockens *)malloc(sizeof(t_tockens));
	g_data.trash_list = ft_add_trash(&g_data.trash_list, new);
	if (!new)
		return (NULL);
	new->word = word;
	new->type = type;
	new->word_after_exp = NULL;
	new->next = NULL;
	return (new);
}

t_tockens	*ft_add_tocken(t_tockens **head, char *word, int type)
{
	t_tockens *new;
	t_tockens *temp;

	new = ft_create_node(word, type);
	if (!new)
		return (NULL);
	if (!*head)
		return (new);
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
	return (*head);
}