#define _POSIX_C_SOURCE 200809L

#include "monty.h"

help_t global;

/**
 * main - The main entry point
 * @av: The list of arguments passed to our program
 * @ac: The argument count
 *
 * Return: nothing
 */
int main(int ac, char **av)
{
	int status = 0;
	FILE *file;
	size_t buf_len = 0;
	char *str = NULL, *buffer = NULL;
	stack_t *stack = NULL;
	unsigned int line_cnt = 1;

	global.data_struct = 1;
	if (ac != 2)
		err_usage();

	file = fopen(av[1], "r");
	if (!file)
		file_err(av[1]);

	while ((getline(&buffer, &buf_len, file)) != -1)
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_cnt++;
			continue;
		}

		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_cnt++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line_cnt);
		line_cnt++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}
