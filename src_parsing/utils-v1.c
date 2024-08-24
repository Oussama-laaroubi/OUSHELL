/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-v1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:58:37 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/22 22:07:49 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    ft_free_exit(char *line, bool val)
{
    free_trash(&g_data.trash_list);
    if(line)
    {
        free(line);
        line = NULL;
    }
    if(val)
        exit(EXIT_SUCCESS);
}

int is_whitespace(int c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}
