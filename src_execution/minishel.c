/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:08:28 by ouboukou          #+#    #+#             */
/*   Updated: 2024/08/14 20:18:51 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 100

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

// Example function to simulate built-in command execution
void	builtin_echo(char **args)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (args[1] && strcmp(args[1], "-n") == 0)
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
		{
			printf(" ");
		}
		i++;
	}
	if (newline)
	{
		printf("\n");
	}
}


size_t double_str_len(char **str)
{
    size_t len = 0;

    while (str[len] != NULL)
        len++;

    return len;
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
		// if (args[0] && strcmp(args[0], "echo") == 0)
		// {
		// 	builtin_echo(args);
		// }
		// else if (args[0] && strcmp(args[0], "exit") == 0)
		// {
		// 	free(input);
		// 	free(args);
		// 	break ; // Exit the mock shell
		// }
		// else
		// {
		// 	printf("Command not recognized.\n");
		// }


	int j = 0;
	while (args[j])
	{
		printf("[%d] -----> %s\n", j, args[j]);
		j++;
	}
	printf("%ld\n", double_str_len(args));

	
	free(input);
	free(args);
	
	}
	return (0);
}
