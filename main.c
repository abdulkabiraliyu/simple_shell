#include "shell.h"

/**
 * execute_exit - execute builtin exit
 *
 * @argv:  argument passed
 *
 * Return: 0
 */

void execute_exit(char **argv)
{
	int status = 0;

	if (argv[1] != NULL)
		status = _atoi(argv[1]);

	free_e(argv);
	exit(status);

}


/**
 * main - simple shell program
 *
 * @ac: argument count
 * @av: pointer to arrays of string
 * @envp: environment variable
 *
 * Return:nothing
 **/

int main(int ac, char __attribute__((__unused__)) **av, char **envp)
{
	char *buff_line;
	size_t buf_line_size = 0;
	char **argv = NULL;
	char *prompt = "[$hell]-$ ";
	(void) ac;
	

	do {
		if (isatty(STDIN_FILENO))
		{
			display_prompt(prompt);
			fflush(stdout);
		}

		buff_line = NULL;

		if (getcommands(&buff_line, &buf_line_size) == -1)
		{
			free(buff_line);
			print_s("Exiting shell ...");
			
			return (0);
		}

		argv = gettokens(buff_line);

		if (_cmpStrings(argv[0], "exit") == 0)
			execute_exit(argv);


		else if (_cmpStrings(argv[0], "cd") == 0)
		{
			change_dir(argv, envp);
			free(argv);
		}
		else
		{
			exec_cmd(argv, prompt, envp);

		}

	} while (1);

	return (EXIT_SUCCESS);
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
