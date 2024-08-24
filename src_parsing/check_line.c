/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:18:01 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/22 22:07:42 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


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

bool    valid_quotes(char *line)
{
    int i;
    int j;
    int len;
    int d_quotes = 0;
    int s_quotes = 0;

    
    if(!line)
        return true;
    len = ft_strlen(line);
    j = 0;
    i = 0;
    while (is_whitespace(line[i]))
        i++;
    while(i < len)
    {
        if(line[i] == 39)
        {
            s_quotes++;
            i++;
            while(line[i])
            {
                if(line[i] == 39)
                {
                    s_quotes++;
                    i++;
                    break;
                }
                i++;
            }
        }
        else if(line[i] == 34)
        {
            d_quotes++;
            i++;
            while(line[i])
            {
                if(line[i] == 34)
                {
                    d_quotes++;
                    i++;
                    break;
                }
                i++;
            }
        }
        else
            i++;
    }
    if((s_quotes % 2 != 0) || (d_quotes % 2 != 0))
        return false;
    return true; 
}   
