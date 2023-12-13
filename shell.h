#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 64
#define MAX_INPUT_SIZE 100

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int _putchar(char c);
void free_e(char **argv);
int print_s(char *str);
void change_dir(char **argv);
void exec_cmd(char **argv, char *prompt, char **envp);
void display_prompt();
int _cmpStrings(const char *string1, const char *string2);
char *get_full_path(char *path, char *cmd);
char *_strtok(char *str, char *dlim);
char **gettokens(char *buff_line);
char * _duplString(const char *str);
int getcommands(char **buff_line, size_t *buf_line_size);
char *_concat_strings(const char *str1, const char *str2);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

char *_strcpy(char *dest, const char *src);


void *_realloc(void *pt, unsigned int old_size, unsigned int new_size);
void assign_bufferptr(char **buffptr, size_t *n, char *buffer, size_t size);
ssize_t _getline(char **bufferptr, size_t *n, FILE *stream);

#endif /* SHELL_H */
