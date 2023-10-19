#include "main.h"

/**
* *_getline_command - Execute the command using execve if found in PATH
* return: the command. 
*/


char *_getline_command(void)
{
	char *lipt = NULL;
	size_t char_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lipt, &char_user, stdin) == -1)
	{
		free(lipt);
		return (NULL);
	}

	return (lipt);
}
