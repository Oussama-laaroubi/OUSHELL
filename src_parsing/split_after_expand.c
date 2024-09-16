/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_after_expand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:00:42 by olaaroub          #+#    #+#             */
/*   Updated: 2024/09/15 19:12:55 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"



static void    refill_tokens(void)
{
    t_tockens   *tmp;
    int         i;

    tmp = g_data.tocken_list;
    g_data.tocken_list = NULL;
    while(tmp)
    {
        i = 0;
        while(tmp->word_after_exp && tmp->word_after_exp[i])
        {
            g_data.tocken_list = ft_add_tocken(tmp->word_after_exp[i], tmp->type, tmp->ambiguous, tmp->dollar);
            i++;
        }
        tmp = tmp->next;
    }
}

void    split_tokens(void)
{
    t_tockens   *tmp;

    tmp = g_data.tocken_list;
    while(tmp)
    {
        if(!tmp->word && (tmp->dollar && tmp->dollar[0] != '\0'))
            tmp->word_after_exp = split_mgem7a(tmp->dollar);
        else
            tmp->word_after_exp = split_mgem7a(tmp->word);
        tmp = tmp->next;
    }
    refill_tokens();
}