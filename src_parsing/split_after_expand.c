/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_after_expand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:00:42 by olaaroub          #+#    #+#             */
/*   Updated: 2024/09/03 14:21:15 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    split_tokens(void)
{
    t_tockens   *tmp;

    tmp = g_data.tocken_list;
    while(tmp)
    {
        tmp->word_after_exp = split_mgem7a(tmp->word);
        tmp = tmp->next;
    }
}