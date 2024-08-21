/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-v1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:58:37 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/21 22:10:28 by olaaroub         ###   ########.fr       */
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
