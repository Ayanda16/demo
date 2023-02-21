#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * main - Entry point of ourshell.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: (EXIT_SUCCESS)
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *stkn;
	ssize_t readcount;
	pid_t my_pid;
	int status, i;
	char **arr = malloc(sizeof(char *) * 32);

	signal(SIGINT, SIG_IGN);

	while (1)
	{
		write(1, "Watchers$", 9);
		readcount = (getline(&line, &len, stdin) != EOF);
		stkn = strtok(line, " \n");
		arr[0] = stkn;

		if (readcount == -1)
		{
			return (-1);
		}

		if (strcmp(arr[0], "exit") == 0)
		{
			exit(0);
		}
		i = 1;
		while (stkn != NULL)
		{
			stkn = strtok(NULL, " \n");
			arr[i] = stkn;
			i++;
		}
		my_pid = fork();
		if (my_pid == -1)
		{
			perror("error");
			return (1);
		}
		else if (my_pid == 0)
		{
			execve(arr[0], arr, NULL);
		}
		else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}
