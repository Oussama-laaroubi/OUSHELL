/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:16:24 by ouboukou          #+#    #+#             */
/*   Updated: 2024/08/14 20:32:59 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

bool  n_option(char *args)
{
    if (args[0] != '-')
        return (false);
    
    int i;

    i = 1;
    while (args[i] != '\0')
    {
        if (args[i] != 'n')
            return (false);
        i++;
    }
    return (true);
}
size_t double_str_len(char **str)
{
    size_t len = 0;

    while (str[len] != NULL)
        len++;

    return len;
}

void echo(int args_n, char **args)
{
    bool newline;
    int i;
    
    newline = true;
    i = 0;
    while (i < args_n && (n_option(args[i]) == true ))
    {
        newline = false;
        i++;
    }
    while (i < args_n)
    {
        printf("%s", args[i]);
        if (i < args_n - 1)
            printf(" ");
    }

    if (newline)
        printf("\n");          
}