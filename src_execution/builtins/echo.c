/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:16:24 by ouboukou          #+#    #+#             */
/*   Updated: 2024/08/27 17:21:11 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>


size_t double_str_len(char **str)
{
    size_t len = 0;

    while (str[len] != NULL)
        len++;

    return len;
}
/////////////////////////////////////////////////
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

void ft_echo(char **args)
{
    bool newline;
    size_t i;
    size_t args_n;

	args_n = double_str_len(args);
	
    newline = true;
    i = 1;
    while (i < args_n && (n_option(args[i]) == true))
    {
        newline = false;
        i++;
    }
    while (i < args_n)
    {
		write (1, args[i], strlen(args[i]));
        if (i < args_n - 1)
            write(1, " ", 1);
		i++;
    }
    if (newline)
        printf("\n");          
}
