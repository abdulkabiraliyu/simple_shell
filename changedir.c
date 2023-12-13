#include "shell.h"

/**
 * change_dir - change directory ( cd )
 *
 * @envp: environment variable
 * @argv: command arguments
 */
void change_dir(char **argv, char **envp)
{

	char *directory;
	char current_directory[MAX_INPUT_SIZE];

	if (argv[1] != NULL)
		directory = argv[1];

	else
		directory = _getenv("HOME", envp);

	if (chdir(directory) == -1)
	{
		perror("Error <chdir>: ");
	}
	else
	{


		if (getcwd(current_directory, sizeof(current_directory)) != NULL)
		{
			_setenv("PWD", current_directory, 1, envp);
		}
		else
		{
			perror("Error <getcwd>: ");
		}
	}
}
