#include "main.h"

/**
* main - Entry point for the custom shell
* @ac: The argument count
* @argv: An array of argument strings
*
* This function initializes the custom shell program by calling executeShell
* with a specified prompt and a pointer for user input. It also passes the
* command-line arguments `ac` and `argv`.
*
* Return: 0 on success.
*/

int main(int ac, char **argv)
{
	(void)ac;
	(void)**argv;
	return (executeShell("(Hi :) $ ", NULL));
}
