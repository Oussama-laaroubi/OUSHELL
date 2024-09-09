/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_command_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:24:13 by olaaroub          #+#    #+#             */
/*   Updated: 2024/09/09 15:05:55 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int len_until_pipe(t_tockens *temp)
{
    t_tockens *tmp;
    int i = 0;

    tmp = temp;
    while(tmp && tmp->type != PIPE)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

static void fill_commands_redirs(t_tockens **temp, t_redir **redir, char **commands)
{
    int i;

    i = 0;
    while(*temp && (*temp)->type != PIPE)
    {
        if((*temp)->type == INPUT || (*temp)->type == OUTPUT || (*temp)->type == APPEND || (*temp)->type == HEREDOC)
        {
            *redir = ft_add_redir(redir, (*temp)->next->word, (*temp)->type);
            (*temp) = (*temp)->next->next;
        }
        else
        {
            commands[i] = ft_strdup((*temp)->word);
            g_data.trash_list = ft_add_trash(&g_data.trash_list, commands[i++]);
            (*temp) = (*temp)->next;
        }
    }
    commands[i] = 0;
}

void    fill_command_list(void)
{
    t_tockens   *temp;
    t_redir     *redir;
    char        **commands;
    int len;

    temp = g_data.tocken_list;
    while (temp)
    {
        len = len_until_pipe(temp);
        commands = (char **)malloc(sizeof(char *) * (len + 1));
        g_data.trash_list = ft_add_trash(&g_data.trash_list, commands);
        redir = NULL;
        fill_commands_redirs(&temp, &redir, commands);
        g_data.command_list = ft_add_command(&g_data.command_list, commands, redir);
        if(temp)
            temp = temp->next;
    }
}
