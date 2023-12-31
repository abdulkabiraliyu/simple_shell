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
	char *buff_line_dup = _duplString(buff_line);
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
		free(buff_line_dup);
		perror("Error <malloc>:");
		exit(EXIT_FAILURE);
	}

	tkns  = _strtok(buff_line, dlim);
	for (i = 0; i < ac; i++)
	{

		av[i] = _duplString(tkns);
		tkns = _strtok(NULL, dlim);

	}

	av[i] = NULL;
	free(buff_line);
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
	char *path = _getenv("PATH", env), *full_path;
	int status;

	if (path != NULL)
	{
		full_path = get_full_path(path, argv[0]);
		if (full_path != NULL)
		{
			if (!isatty(STDIN_FILENO))
       			{
				if (execve(full_path, argv, env) == -1)
                                {
                                        perror(prompt);
                                        exit(EXIT_FAILURE);
                                }
                	
        		}
			else {

			p_id = fork();
			if (p_id == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (p_id == 0)
			{
				if (execve(full_path, argv, env) == -1)
				{
					perror(prompt);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&status);
				free_e(argv);
				free(full_path);
			}
			}

		}
		else
		{
			perror(prompt);
			free(full_path);
		}
	}
	else
	{
		perror("Error <PATH is NULL>");
	}
}
/*
 * built_in_commands - execute shell built in commands
 *
 * @argv: array of strings containing commands and arguments
 *
 * Return: true if command is built in or false otherwise
 */
bool built_in_commands(char **argv, char **envp)
{
	int i;
	if (_cmpStrings(argv[0], "exit") == 0)
	{
		execute_exit(argv);
		return (true);
	}


      else if (_cmpStrings(argv[0], "cd") == 0)
      {
              change_dir(argv, envp);
              free(argv);
	      return (true);
      }
	else if (_cmpStrings(argv[0], "env") == 0)
	{
		i = 0;
		while (envp[i] != NULL)
		{
			print_s(envp[i]);
			i++;
		}
	}

 
  return (false);
}
