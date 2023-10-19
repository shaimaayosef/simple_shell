#include "main.h"

/**
* main - Entry point for the custom shell
* @ac: The argument count
* @av: An array of argument strings
* @env the enver
* This function initializes the custom shell program by calling executeShell
* with a specified prompt and a pointer for user input. It also passes the
* command-line arguments `ac` and `argv`.
*
* Return: 0 on success.
*/

int main(int ac, char **av, char **env)
{
	int pathV = 0, status = 0, is_path = 0;
char *li = NULL,  **commands = NULL; 
	(void)ac;
	while (1)/* sitll working exit */
	{
		erro = 0;
		li = _getline_command();/** reas endu input*/
		if (line == NULL && erro == 0)
			return (0);
		if (li)
		{
			pathV++;
commands = tokenize(li);
			if (!commands)
				free(li);
if (!_strcmp(commands[0], "env"))
				_getenv(env);
			else
			{
is_path = _values_path(&commands[0], env);/** token PATH*/
status = _fork_fun(commands, av, env, li, pathV, is_path);
					if (status == 200)
					{
						free(li);
						return (0);
					}
				if (is_path == 0)
					free(commands[0]);
			}
			free(commands); /*free up memory*/
		}
		else
		{
			if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
			exit(status);
		}
		free(li);
	}
	return (status);
}
