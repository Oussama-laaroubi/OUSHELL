/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:44:05 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/28 21:05:13 by olaaroub         ###   ########.fr       */
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
		printf("value == %s type == %u \n", token->word, token->type);
        // if(token->prev)
		//     printf("prev value == %s\n", token->prev->word);
		token = token->next;
	}
}

void    init_data(void)
{
    g_data.env_list = NULL;
    g_data.trash_list = NULL;
    g_data.tocken_list = NULL;
}

int main(int ac, char **av, char **env)
{
    char *line;
    
    (void)ac;
    (void)av;
    line = NULL;
    while(1)
    {
        init_data();
        get_env(&g_data.env_list, env);
        line = readline("Minihell==>>$ ");
        if(line && *line)
            add_history(line);
        if(line && !ft_strcmp(line, "exit"))
            ft_free_exit(line, true);
        ft_white_spaces(line);
        if(!valid_quotes(line))
        {
            printf("Error: Unclosed quotes detected.\n");
            ft_free_exit(line, false);
            continue;
        }
        line = add_space(line);
        tockenizing(line);
        // printf("%s\n",  line);
        print_tokens(g_data.tocken_list);
        // syntax_error(line); //TODO
        ft_free_exit(line, false);
    }
}
