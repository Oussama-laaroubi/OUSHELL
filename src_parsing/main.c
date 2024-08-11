/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:44:05 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/11 17:50:50 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_program   g_data;

int main(int ac, char **av, char **env)
{
    t_program   program;
    char *line = NULL;
    
    program.trash_list = NULL;
    program.tocken_list = NULL;
    (void)ac;
    (void)av;
    while(1)
    {
        get_env(&program.env_list, env);
        if(line)
        {
            free(line);
            line = NULL;
        }
        line = readline("Enter a text: ");
        tockenizing(line);
 
        if(line && *line)
            add_history(line);
        free_trash(&program.trash_list);
    }
}