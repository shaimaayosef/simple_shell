#include "main.h"

/**
* executeCommand - Execute the command using execve if found in PATH
* @command: The command to execute
* @argv: An array of arguments
*/

void executeCommand(char *command, char **argv)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	if (strcmp(command, "env") == 0)
	{
		char *env_var;
		int i;

		for (i = 0; environ[i] != NULL; i++)
		{
			env_var = environ[i];
			printf("%s\n", env_var);
		}
		return;
	}
	if (path == NULL)
	{
		perror("Unable to access PATH");
		return;
	}
	if (path_copy == NULL)
	{
		perror("Error:");
		return;
	}
	while (dir != NULL)
	{
		searchAndExecute(command, argv, dir);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	execve("/bin/ls", argv, NULL);
	perror("Command not found");
}
