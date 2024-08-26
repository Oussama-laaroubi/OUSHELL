/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:03:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/26 17:23:00 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int syntax_error(char *line)
{
    int ret;
    int i;
    t_tockens   *tmp;
    
    i = 0;
    tmp = g_data.tocken_list;
    while(tmp)
    {
        if(tmp->type == PIPE)
        {
            
        }
        
    }
}