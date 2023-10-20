#include "main.h"

/*
 * List  func wich used
 */

int lsh_cd(char **args);
int lsh_hlp(char **args);
int lsh_ex(char **args);
int lsh_ctrD(char **args);

char *builtin_st[] = {"cd", "help", "exit", "^D"};

int (*builtin_function[]) (char **) = {&lsh_cd, &lsh_hlp, &lsh_ex, &lsh_ctrD};

/**
 * lsh_num_builtin - size of char
 * Return: size
 */

int lsh_num_builtin(void)
{
	return (sizeof(builtin_st) / sizeof(char *));
}


/**
 * lsh_cd - build to change dir
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: 1 on success
 */
int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * lsh_hlp - prints the help
 * @args: List of args.  Not examined.
 * Return: Always returns 1, to continue executing.
 */
int lsh_hlp(char **args)
{
	int i;

	printf("ahmed & shaimaa\n");
	printf("If you need help, contact us on email\n");
	(void)args;
	for (i = 0; i < lsh_num_builtin(); i++)
	{
		printf("  %s\n", builtin_st[i]);
	}

	return (1);
}

/**
 * lsh_ex -   exit from the shell
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int lsh_ex(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * lsh_ctrD -  handle "^D" call
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int lsh_ctrD(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 *_fork_fun - foo that create a fork.
 *@arg: Command and values path.
 *@av: Has the name of our program.
 *@env: Environment
 *@lineptr: Command line for the user.
 *@np: ID of proces.
 *@c: Checker add new test
 *Return: 0 success
 */

int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{

	pid_t child;
	int status, i = 0;
	char *format = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (1);
	for (i = 0; i < lsh_num_builtin(); i++)
	{
		if (_strcmp(arg[0], builtin_st[i]) == 0)
			return (builtin_function[i](arg));
	}
	child = fork();
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}
