#include "shell.h"

/**
 * change_dir - change directory ( cd )
 *
 * @argv: command arguments
 */
void change_dir(char **argv)
{

	char *directory;
	char current_directory[MAX_INPUT_SIZE];

	if (argv[1] != NULL)
		directory = argv[1];

	else
		directory = getenv("HOME");

	if (chdir(directory) == -1)
	{
		perror("Error <chdir>: ");
	}
	else
	{


		if (getcwd(current_directory, sizeof(current_directory)) != NULL)
		{
			setenv("PWD", current_directory, 1);
		}
		else
		{
			perror("Error <getcwd>: ");
		}
	}
}
