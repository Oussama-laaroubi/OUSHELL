/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:44:05 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/09 16:31:45 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_program   g_data;

int main(int ac, char **av, char **env)
{
    t_program   program;
    char *line = NULL;
    
    program.trash_list = NULL;
    (void)ac;
    (void)av;
    while(1)
    {
        if(line)
        {
            free(line);
            line = NULL;
        }
        line = readline("Enter a text: ");
        printf("%d\n", count_words(line));
        if(line && *line)
            add_history(line);
        free_trash(&program.trash_list);
    }
    get_env(&program.env_list, env);
}