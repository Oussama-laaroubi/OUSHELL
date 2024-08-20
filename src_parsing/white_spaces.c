/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:18:01 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/16 22:17:54 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int is_whitespace(int c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}
void ft_white_spaces(char *line)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    if(!line)
        return;
    len = ft_strlen(line);
    while (is_whitespace(line[i]))
        i++;
    while (i < len)
    {
        if (is_whitespace(line[i])) 
        {
            line[j++] = ' ';
            while (is_whitespace(line[i]))
                i++;
        } 
        else
            line[j++] = line[i++];
    }
    if (j > 0 && is_whitespace(line[j-1]))
        j--;
    line[j] = '\0';
}
