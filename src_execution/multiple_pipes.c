#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main()
{
	int	pipefd[2];
	int	i;

	int in_fd = STDIN_FILENO; // Initial input is from stdin
	i = 0;
	char *commands[][3] = {
		{"ls", "-l", NULL},
		{"grep", "main", NULL},
		{"wc", "-l", NULL}};

	while (i < 3)
	{
		pipe(pipefd); // Create a pipe for this pair of commands
		if (fork() == 0)
		{
			// Child process
			dup2(in_fd, STDIN_FILENO);
				// Redirect input from the last pipe (or stdin for the first command)
			if (i < 2)
			{                                   // If not the last command
				dup2(pipefd[1], STDOUT_FILENO);
					// Redirect output to the current pipe
			}
			close(pipefd[0]);                   
				// Close the read end in the child process
			execvp(commands[i][0], commands[i]); // Execute the command
			perror("execvp failed");
			return (1);
		}
		else
		{
			// Parent process
			wait(NULL);        // Wait for the child to finish
			close(pipefd[1]);  // Close the write end in the parent process
			in_fd = pipefd[0];
				// Save the read end to use as input for the next command
			i++;
		}
	}
	return (0);
}
