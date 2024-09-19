/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:08:28 by ouboukou          #+#    #+#             */
/*   Updated: 2024/08/27 19:09:40 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"


// size_t double_str_len(char **str)
// {
//     size_t len = 0;

//     while (str[len] != NULL)
//         len++;

//     return len;
// }

// Function to mock parsing input into arguments
char	**mock_parse_command(char *input)
{
	char	**args;
	int		i;
	char	*token;

	args = malloc(MAX_ARGS * sizeof(char *));
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	token = strtok(input, " \t\n");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL; // Null-terminate the array of arguments
	return (args);
}

int	main(void)
{
	char	*input;
	char	**args;

	while (1)
	{
		input = readline("mock_shell> ");
		if (!input)
			break ; // EOF (Ctrl+D)
		
		if (*input)
			add_history(input); // Add non-empty input to history
			
		args = mock_parse_command(input);

		
		// // Example execution of the echo builtin
		if (args[0] && strcmp(args[0], "echo") == 0)
			ft_echo(args);
		
		else if (args[0] && strcmp(args[0], "exit") == 0)
		{
            free(input);
            free(args);
            break; // Exit the mock shell
        }
		
		else
			printf("Command not recognized.\n");

	// int j = 0;
	// while (args[j])
	// {
	// 	printf("[%d] -----> %s\n", j, args[j]);
	// 	j++;
	// }
	// printf("%ld\n", double_str_len(args));

	
	free(input);
	free(args);
	
	}
	return (0);
}
