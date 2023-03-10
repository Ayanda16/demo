#include"main.h"
/**
 * tokenize - Separates a string into an array of tokens. DON'T FORGET TO FREE
 * on receiving function when using tokenize.
 * @token_count: An integer representing the amount of tokens in the array.
 * @command: String that is separated by an specified delimeter
 * @delim: The desired delimeter to separate tokens.
 * Return: Upon success a NULL terminated array of pointer to strings.
 * Otherwise returns NULL.
 */
char **tokenize(int token_count, char *command, const char *delim)
{
	int i;
	char **buffer;
	char *token;
	char *line_cp;

	line_cp = strdup(command);
	buffer = malloc(sizeof(char *) * (token_count + 1));
	if (buffer == NULL)
		return (NULL);
	token = strtok(line_cp, delim);
	for (i = 0; token != NULL; i++)
	{
		buffer[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	buffer[i] = NULL;
	free(line_cp);
	return (buffer);
}

/**
 * count_token - Counts tokens in the passed string.
 * @command: String that is separated by an specified delimeter
 * @delim: The desired delimeter to separate tokens.
 * Return: Upon success the total count of the tokens. Otherwise -1.
 */
int count_token(char *command, const char *delim)
{
	char *str;
	char *token;
	int i;

	str = strdup(command);
	if (str == NULL)
		return (-1);
	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);
	free(str);
	return (i);
}
/**
 * tokenize_path - Separates a string representing paths as an array
 * of strings contining the path directories.
 * @index: Index of the path in the environment variables.
 * @str: string to separate and tokenize.
 * Return: Upon success a NULL terminated array of pointer to strings.
 * Otherwise returns NULL. Note!: Do not forget to free alocated
 * memory on receiving function or when possible.
 */
char **tokenize_path(int index, char *str)
{
	char *env_var;
	int token_count;
	const char *delim = ":\n";
	char **pathtok;
	int len;

	len = strlen(str);
	token_count = 0;
	env_var = environ[index] + (len + 1);
	pathtok = token_interface(env_var, delim, token_count);
	if (pathtok == NULL)
		return (NULL);
	return (pathtok);
}
/**
 * token_interface - Meant to interact with other token functions, and make
 * them more accessible to other parts of the program.
 * @command: A string containing the raw user input.
 * @delim: A constant string containing the desired delimeter to tokenize line.
 * @token_count: A holder for the amount of tokens in a string.
 * Return: Upon success an array of tokens representing the command. Otherwise
 * returns NULL.
 */
char **token_interface(char *command, const char *delim, int token_count)
{
	char **param_array;

	token_count = count_token(command, delim);
	if (token_count == -1)
	{
		free(command);
		return (NULL);
	}
	param_array = tokenize(token_count, command, delim);
	if (param_array == NULL)
	{
		free(command);
		return (NULL);
	}
	return (param_array);
}
