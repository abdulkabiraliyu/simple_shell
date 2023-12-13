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
	char *buff_line;
	size_t buf_line_size = 0;
	char **argv = NULL;
	char *prompt = "[$hell]-$ ";
	(void) ac, (void) av;

	do {
		if (isatty(STDIN_FILENO))
			display_prompt(prompt);

		buff_line = NULL;

		if (getcommands(&buff_line, &buf_line_size) == -1)
		{
			free(buff_line);
			return (-1);
		}

		argv = gettokens(buff_line);

		if (_cmpStrings(argv[0], "exit") == 0)
		{
			free_e(argv);
			break;
		}
		else if (_cmpStrings(argv[0], "cd") == 0)
		{
			change_dir(argv);
			free(argv);
		}
		else
		{
		exec_cmd(argv, prompt, envp);

		}

	} while (1);

	return (0);
}

/**
 * free_e - free memory allocation
 * @argv: pointer to the memory
 *
 */

void free_e(char **argv)
{
	char **temp = argv;

	while (*temp != NULL)
	{
		free(*temp);
		temp++;
	}
	free(argv);
}
