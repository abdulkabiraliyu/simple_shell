#include "shell.h"

/**
 * display_prompt - display prompt in the terminal
 *
 * @prompt: shell prompt
 */

void display_prompt(char *prompt)
{
	
	print_s(prompt);
	fflush(stdout);
}
