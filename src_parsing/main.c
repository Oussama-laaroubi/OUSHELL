/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:44:05 by olaaroub          #+#    #+#             */
/*   Updated: 2024/09/09 14:21:29 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_program g_data;

void print_tokens()
{
	t_command *token;
	int i;

	token = g_data.command_list;
	while (token)
	{
		i = 0;
		printf("=== COMMANDS ===\n");
		while (token->cmd[i])
		{
			printf(" command %i is %s\n", i, token->cmd[i]);
			i++;
		}
		printf("=== REDIRS ===\n");
		while(token->red)
		{
			printf(" type is %d file name is %s\n", token->red->type, token->red->file_name);
			token->red = token->red->next;
		}
		token = token->next;
		printf("========================================================\n");
	}
}

void init_data(void)
{
	g_data.env_list = NULL;
	g_data.trash_list = NULL;
	g_data.command_list = NULL;
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
		line = readline("Minihell==>>$ ");
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
		fill_command_list();
		print_tokens();
		// while(g_data.command_list)
		// {
		// 	int i = 0;
		// 	while(g_data.command_list->cmd[i])
		// 	{
		// 		printf("=== %s ===\n", g_data.command_list->cmd[i]);
		// 		i++;
		// 	}
		// 	g_data.command_list = g_data.command_list->next;
		// }
		ft_free_exit(line, false);
	}
}
