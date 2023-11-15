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
	char *f_path, *tokns, *dlim = ":";
	char *path_cpy = strdup(path);

	if (access(cmd, X_OK) == 0)
	{
		free(path_cpy);
		return (cmd);
	}

	f_path = malloc(sizeof(char) * 1024);


	tokns = strtok(path_cpy, dlim);

	while (tokns)
	{
		f_path = _concat_strings(tokns, "/");
		f_path = _concat_strings(f_path, cmd);

		if (access(f_path, X_OK) == 0)
		{
			free(path_cpy);
			return (f_path);
		}

		tokns = strtok(NULL, dlim);
	}

	return (NULL);
}

