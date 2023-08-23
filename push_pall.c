#include "monty.h"

/**
 * push - function that push elements into the stack
 * @stack: the stack head
 * @line_cnt: the amount of lines
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	char *n;

	n = global.argument;
	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: Usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
			exit(EXIT_FAILURE);
	}
}


/**
 * pall - function that prints the stack
 * @stack: the stack head
 * @line_cnt: the amount of lines
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}
