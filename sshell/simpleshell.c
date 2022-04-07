#include "main.h"

/**
 * main - as
 * Return - qw
 */

int main()
{
	char *env = NULL, *buffer = NULL;
	size_t size = 0;
	ssize_t bytes = 0;
	int space = 0, status = 0, exitstatus = 1, slash = 0;
	tokeniza *directorys = NULL, *input = NULL;

	env = getpath(); /*obtenemos path de la variable environ*/
	tokenizer(env, &directorys, ":"); /*tokenizamos y enviamos a una lista los directorios*/
	signal(SIGINT, _signal);	
	while(1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("#DASH: ");
		bytes = getline(&buffer, &size, stdin);
		if (bytes == -1)
		{
			printf("\n");
			break;
		}
		buffer[strlen(buffer) - 1] = '\0';
		exitstatus = fexit(buffer);
		if (exitstatus == 0)
			exit(EXIT_SUCCESS);
		space = check_space(buffer);
		slash = check_slash(buffer);
		if (buffer[0] != '\n' && space != 0)
		{
			tokenizer(buffer, &input, " ");
			if (slash == 1)
				status = check_directory(input);
			else
				status = check_files(directorys, input);
			free_nodes(input);
			input = NULL;
		}
		if (isatty(STDIN_FILENO) != 1)
			break;
	}
	free(buffer);
	free_nodes(directorys);
	return (status);
}
