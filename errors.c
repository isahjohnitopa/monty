#include "monty.h"

/**
 * file_err - Function that prints file error message and exits
 * @argv: The argument list given by main()
 *
 * Desc: print message if not possible to open the file
 * Return: nothing
 */
void file_err(char *argv)
{
	fprintf(strerr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}


/**
 * err_usage - Function that prints useage message error and exits
 * Desc: If user does not five any file or more than
 * one argument to your program
 *
 * Return: nothing
 */
void err_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
