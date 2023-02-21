#ifndef _MAIN_H_
#define _MAIN_H_

/*   Libraries. */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <signal.h>

/**
 * struct builtin_d - defines the builtin functions
 * @built: name of the build in command
 * @f: pointer to builtin function'
 */

typedef struct builtin_d
{
	char *built;
	void (*f)(char *);
} builtin_t;

/*   Our functions. */
extern char **environ;
char **token_interface(char *, const char *, int);
int count_token(char *, const char *);
char **tokenize(int, char *, const char *);
void create_child(char **, char *, int, char **);
void parse_line(char *, size_t, int, char **);
char *path_finder(char *);
int str_len(char *);
int find_path(char *);
char **tokenize_path(int, char *);
char *search_directories(char **, char *);
char *build_path(char *, char *);
void double_free(char **);
void single_free(int, ...);
void print_str(char *, int);


/*   Generic functions. */

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *);

/*Builtin functions*/
int built_in(char **, char *);
void (*check_built_ins(char *))(char *);
void ourexit(char *);
void penv(chari *envp);
void ourcd(char *);

#endif /* _MAIN_H_ */
