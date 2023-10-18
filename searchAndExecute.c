#include "main.h"

/**
* searchAndExecute - Search and execute the command in PATH
* @command: The command to execute
* @argv: An array of arguments
* @dir: A directory path from PATH
*/

void searchAndExecute(char *command, char **argv, char *dir)
{
	char *full_path = malloc(strlen(dir) + strlen(command) + 2);

	if (full_path != NULL)
	{
		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			pid_t child_pid = fork();

			if (child_pid == -1)
			{
				perror("Fork error");
				exit(EXIT_FAILURE);
			}

			if (child_pid == 0)
			{
				execve(full_path, argv, NULL);
				perror("execve");
				exit(EXIT_FAILURE);
			}
		else
		{
			int status;

			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			{
				free(full_path);
				executeShell("(Hi :) $ ", NULL);
				fflush(stdout);
				exit(EXIT_SUCCESS);
				}
				}
				}
				free(full_path);
				}
}
