/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handling Redirection and Pipes.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:37:22 by ouboukou          #+#    #+#             */
/*   Updated: 2024/09/19 15:37:40 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/minishell.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	handle_redirection(char **args)
{
	int	i;
	int	fd;
	int	fd;

	i = 0;
	while (args[i] != NULL)
	{
		if (strcmp(args[i], ">") == 0)
		{
			fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd < 0)
			{
				perror("open");
				return ;
			}
			dup2(fd, STDOUT_FILENO);
			close(fd);
			args[i] = NULL; // Terminate arguments at redirection
		}
		if (strcmp(args[i], "<") == 0)
		{
			fd = open(args[i + 1], O_RDONLY);
			if (fd < 0)
			{
				perror("open");
				return ;
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
			args[i] = NULL; // Terminate arguments at redirection
		}
		i++;
	}
}

void	handle_pipes(char **args)
{
	int		pipe_fds[2];
	pid_t	pid;

	// Example of handling pipes
	pipe(pipe_fds);
	if ((pid = fork()) == 0)
	{
		// Child process
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		// Parent process
		wait(NULL);
		dup2(pipe_fds[0], STDIN_FILENO);
		close(pipe_fds[1]);
		close(pipe_fds[0]);
		// Execute the next command
	}
}
