/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:44:05 by olaaroub          #+#    #+#             */
/*   Updated: 2024/09/03 16:33:59 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_program g_data;

void print_tokens(t_tockens *tokens)
{
	t_tockens *token;
	int i;

	token = tokens;
	while (token)
	{
		i = 0;
		printf("--> word is %s\n", token->word);
		while(token->word_after_exp && token->word_after_exp[i])
			printf("--> word after expand is %s\n", token->word_after_exp[i++]);
		
		token = token->next;
	}
}

void init_data(void)
{
	g_data.env_list = NULL;
	g_data.trash_list = NULL;
	g_data.tocken_list = NULL;
	g_data.double_flag = false;
	g_data.single_flag = false;
}

int main(int ac, char **av, char **env)
{
	char *line;

	(void)ac;
	(void)av;
	line = NULL;
	while (1)
	{
		init_data();
		get_env(&g_data.env_list, env);
		line = readline("Minihell==>>$ ");//
		if (line && *line)
			add_history(line);
		if (line && !ft_strcmp(line, "exit"))
			ft_free_exit(line, true);
		ft_white_spaces(line);
		if (!valid_quotes(line))
		{
			printf("Error: Unclosed quotes detected.\n");
			ft_free_exit(line, false);
			continue;
		}
		line = add_space(line);
		tockenizing(line);
		syntax_error(); 
		expand();
		split_tokens();
		print_tokens(g_data.tocken_list);
		ft_free_exit(line, false);
	}
}
