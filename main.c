#include "shell.h"

/**
 * main - simple shell program
 *
 * @ac: argument count
 * @av: pointer to arrays of string
 * @envp: environment variable
 *
 * Return:nothing
 **/

int main(int ac, char **av, char **envp)
{
	char *buff_line = NULL;
	size_t buf_line_size = 0;
	char *prmpt = "[$hell]-$ ";
	char **argv = NULL;

	(void) ac;
	(void) av;

	do {
		if (isatty(STDIN_FILENO))
			display_prompt(prmpt);

		if (getcommands(&buff_line, &buf_line_size) == -1)
			return (-1);

		argv = gettokens(buff_line);

		if (strcmp(argv[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		else if (strcmp(argv[0], "cd") == 0)
		{
			change_dir(argv);
		}
		else
		{
			exec_cmd(argv, prmpt, envp);
		}

	} while (1);

	free(buff_line);

	free_e(argv);

	return (0);

}

/**
 * free_e - free memory allocation
 * @argv: pointer to the memory
 *
 */

void free_e(char **argv)
{
	while (*argv != NULL)
	{
		free(*argv);
		argv++;
	}
	free(argv);
}
