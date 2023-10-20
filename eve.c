#include "main.h"


/**
 * _geteve - ptr of stadnder command
 * @eve: eve
 *
 */

void _geteve(char **eve)
{
	size_t play = 0;

	while (eve[play])
	{
		write(STDOUT_FILENO, eve[play], _strlen(eve[play]));
		write(STDOUT_FILENO, "\n", 1);
		play++;
	}
}
