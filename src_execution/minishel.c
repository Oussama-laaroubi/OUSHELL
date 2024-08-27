/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:08:28 by ouboukou          #+#    #+#             */
/*   Updated: 2024/08/27 17:21:28 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#define MAX_ARGS 100


// size_t double_str_len(char **str)
// {
//     size_t len = 0;

//     while (str[len] != NULL)
//         len++;

//     return len;
// }

// /////////////////////////////////////////////////
// bool  n_option(char *args)
// {
//     if (args[0] != '-')
//         return (false);
    
//     int i;

//     i = 1;
//     while (args[i] != '\0')
//     {
//         if (args[i] != 'n')
//             return (false);
//         i++;
//     }
//     return (true);
// }

// void ft_echo(char **args)
// {
//     bool newline;
//     size_t i;
//     size_t args_n;

// 	args_n = double_str_len(args);
	
//     newline = true;
//     i = 1;
//     while (i < args_n && (n_option(args[i]) == true))
//     {
//         newline = false;
//         i++;
//     }
//     while (i < args_n)
//     {
// 		write (1, args[i], strlen(args[i]));
//         if (i < args_n - 1)
//             write(1, " ", 1);
// 		i++;
//     }
//     if (newline)
//         printf("\n");          
// }
/////////////////////////////////////////////////

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

		else
		{
			printf("Command not recognized.\n");
		}

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
