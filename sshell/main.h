#ifndef SIMPLESHELL
#define SIMPLESHELL
#define EISDIR 21
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

extern int errno;
extern char **environ;

/**
 * struct tokenizar - strut para guardar tokens
 * @s: tokens
 * @next: siguiente nodo
 */

typedef struct tokenizar
{
	char *s;
	struct tokenizar *next;
} tokeniza;


char *_strdup(char *str);
int _strlen(char *s);

void addnode(tokeniza **head, char *s);
void free_nodes(tokeniza *head);

void tokenizer(char *env, tokeniza **directorys, const char *delim);
char *_concat(tokeniza *dir, tokeniza *input);
int command(tokeniza *head, char *path_concat);
int get_stat(char *path_concat);
char *getpath();

void _signal(int sig);
int regular_file(char *s);
int fexit(char *buffer);

int check_directory(tokeniza *input);
int check_files(tokeniza *directorys, tokeniza *input);

int check_slash(char *s);
int check_space(char *s);

#endif

