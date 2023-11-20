#include "shell.h"

/**
 * get_full_path - get absolute path to the command file
 *
 * @path: path to environmental varible path
 * @cmd: command to look for
 *
 * Return: the full path if the program file is found
 **/

char *get_full_path(char *path, char *cmd)
{
	char *f_path = NULL, *tokns, *dlim = ":";
	char *path_cpy = strdup(path);
	char *concat;

	if (path_cpy == NULL)
	{
		perror("Error <strdup>");
		return (NULL);
	}

	if (access(cmd, X_OK) == 0)
	{
		free(path_cpy);
		return (strdup(cmd));
	}

	tokns = strtok(path_cpy, dlim);

	while (tokns)
	{
		concat  = _concat_strings(tokns, "/");

		if (concat != NULL)
		{
			f_path = _concat_strings(concat, cmd);
			free(concat);

			if (f_path != NULL && access(f_path, X_OK) == 0)
			{
				free(path_cpy);
				return (f_path);

			}
			free(f_path);
		}

		tokns = strtok(NULL, dlim);
	}
	free(path_cpy);
	return (NULL);
}

