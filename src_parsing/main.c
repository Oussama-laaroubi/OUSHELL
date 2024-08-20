/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:44:05 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/16 22:05:05 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_program   g_data;

void	print_tokens(t_tockens *tokens)
{
	t_tockens	*token;

	token = tokens;
	while (token)
	{
		printf("value => '%s'\n", token->word);
		printf("type => '%u'\n", token->type);
		token = token->next;
	}
}

int main(int ac, char **av, char **env)
{
    char *line = NULL;
    
    (void)ac;
    (void)av;
    while(1)
    {
        g_data.env_list = NULL;
        g_data.trash_list = NULL;
        g_data.tocken_list = NULL;
        get_env(&g_data.env_list, env);
        
        line = readline("Enter a text: ");
        printf("== BEFORE == %s\n", line);
        if(line && *line)
            add_history(line);
        ft_white_spaces(line);
        printf("== AFTER == %s\n", line);
        // tockenizing(line);
        // print_tokens(g_data.tocken_list);
        free_trash(&g_data.trash_list);
        if(line)
        {
            free(line);
            line = NULL;
        }
    }
}
