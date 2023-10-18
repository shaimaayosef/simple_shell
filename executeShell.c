#include "main.h"

/**
* executeShell - A basic shell program for command execution.
* @prompt: The shell prompt.
* @lineptr: Pointer to user input.
* Return: Always returns 0.
*/

int executeShell(char *prompt, char *lineptr)
{
	size_t n = 0;
	ssize_t nchars_read;
	int num_tokens = 0;
	char *command = NULL;
	char **tokenized_args = NULL;
	int i;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		tokenizeInput(lineptr, &tokenized_args, &num_tokens);
		if (tokenized_args)
		{
			command = tokenized_args[0];

			if (strcmp(command, "exit") == 0)
			{
				/* If the user enters "exit," exit the shell. */
				printf("Goodbye....\n");
				break;
				}
				/* Handle closing with Ctrl+D */
				if (nchars_read == -1)
				{
					printf("Exiting shell....\n");
					break;
					}
					executeCommand(command, tokenized_args);
					for (i = 0; i < num_tokens - 1; i++)
					{
						free(tokenized_args[i]);
						}
						free(tokenized_args);
						}
						}
						free(lineptr);
						return (0);
}
