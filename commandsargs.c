#include "shell.h"

/**
 * getcommands - get command and arguments from the shell terminal
 *
 * @buff_line: pointer to the input commands
 * @buf_line_size: size of the buffer
 *
 * Return: number of bytes read.
 */

int getcommands(char **buff_line, size_t *buf_line_size)
{

	ssize_t bytes_r;

	bytes_r = _getline(buff_line, buf_line_size, stdin);

	return (bytes_r);

}

/**
 * gettokens - convert the command strings to tokens
 *
 * @buff_line: pointer to the input commands
 *
 * Return: each token
 */

char **gettokens(char *buff_line)
{
	char *buff_line_dup = strdup(buff_line);
	char **av = NULL;
	char *tkns = NULL, *dlim = " \n";
	int ac = 0, i;

	tkns = _strtok(buff_line_dup, dlim);
	while (tkns)
	{

		tkns = _strtok(NULL, dlim);
		ac++;
	}

	av = malloc(sizeof(char *) * (ac + 1));

	if (av == NULL)
	{
		perror("Error <malloc>:");
		exit(EXIT_FAILURE);
	}


	tkns  = _strtok(buff_line, dlim);
	for (i = 0; i < ac; i++)
	{

		av[i] = strdup(tkns);
		tkns = _strtok(NULL, dlim);

	}
	av[i] = NULL;

	free(buff_line_dup);

	return (av);

}

/**
 * exec_cmd - execute commands
 *
 * @argv: arguments passed to the command
 * @prompt: prompt command
 * @env: environment variable.
 */

void exec_cmd(char **argv, char *prompt, char **env)
{
	pid_t p_id;
	char *path = getenv("PATH");
	char *full_path;
	int status;

	if (path != NULL)
		full_path  = get_full_path(path, argv[0]);

	else
	{
		perror("Error <PATH is NULL>");
	}
	p_id = fork();
	if (p_id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (p_id == 0)
	{
		if (full_path != NULL)
		{
			if (execve(full_path, argv, env) == -1)
			{
				perror(prompt);
				exit(EXIT_FAILURE);
			}

		}


	}
	else
	{
		wait(&status);
	}
}
