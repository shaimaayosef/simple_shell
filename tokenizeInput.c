#include "main.h"

/**
* tokenizeInput - Tokenize the input line
* @lineptr: The input line to tokenize
* @argv: A pointer to the array of arguments
* @num_tokens: A pointer to store the number of tokens
*/

void tokenizeInput(char *lineptr, char ***argv, int *num_tokens)
{
	const char *delim = " \n";

	char *token;

	int i = 0;

	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		(*num_tokens)++;
		token = strtok(NULL, delim);
	}
	(*num_tokens)++;

	*argv = malloc(sizeof(char *) * (*num_tokens));

	token = strtok(lineptr, delim);

	for (i = 0; token != NULL; i++)
	{
		(*argv)[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	(*argv)[i] = NULL;
}
