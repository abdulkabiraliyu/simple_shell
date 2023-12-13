#include "shell.h"

/**
 * _getenv - get environment variables
 *
 * @name: variable type arg
 *
 * Return: the variable
 */

char *_getenv(const char *name, char **envp)
{


	int i = 0;
	char *env = NULL;

	while (envp[i] != NULL)
	{
		int j = 0;

		while (name[j] != '\0' && envp[i][j] != '=' && name[j] == envp[i][j])
		{
			j++;
		}

		if (name[j] == '\0' && envp[i][j] == '=')
		{
			env = &(envp[i][j + 1]);
			break;
		}

		i++;
	}

	return (env);
}

/**
 * _setenv - set a new environment
 *
 * @name: name of the environment variable
 * @value: value
 * @overwrite: overwrite
 * @envp: environment
 *
 * Return: nothing
 */
int _setenv(const char *name, const char *value, int overwrite, char **envp)
{
	char *new_var;
    char **current = envp;
    char **new_envp = envp;
    int env_count = 0;
    int i, j;
    
    while (*current != NULL)
    {
        current++;
        env_count++;
    }

    
    for (i = 0; i < env_count; i++)
    {
        char *current_var = *(envp + i);
        j = 0;

        
        while (name[j] != '\0' && current_var[j] != '=' && name[j] == current_var[j]) 
        {
            j++;
        }

        
        if (name[j] == '\0' && current_var[j] == '=')
        {
            if (overwrite == 0)
            {
                return (0); 
            } else
	    {
             while (*value != '\0')
		{
                    current_var[j + 1] = *value;
                    value++;
                    j++;
                }
                current_var[j + 1] = '\0'; 
                return (0); 
            }
        }
    }

    
    while (*new_envp != NULL)
    {
        new_envp++;
    }

    if ((new_envp - envp) >= MAX_ENV_VARS - 1)
    {
        return (-1); 
    }

    
    new_var = *(new_envp - 1) + 1; 
    
    while (*name != '\0')
    {
        *new_var++ = *name++;
    }
    *new_var++ = '=';
    while (*value != '\0')
    {
        *new_var++ = *value++;
    }
    *new_var = '\0'; 

   
    *(char **)(new_var + 1) = NULL;

    return (0); 
}

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
	char *path_cpy = _duplString(path);
	char *concat;

	if (path_cpy == NULL)
	{
		perror("Error <strdup>");
		return (NULL);
	}

	if (access(cmd, X_OK) == 0)
	{
		free(path_cpy);
		return (_duplString(cmd));
	}

	tokns = _strtok(path_cpy, dlim);

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

		tokns = _strtok(NULL, dlim);
	}
	free(path_cpy);
	return (NULL);
}

