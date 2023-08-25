#include "monty.h"

/**
 * pstr - function that prints the contents of a stack as a string
 * @stack: pointer to the head of the stack
 * @line_cnt: the number of lines
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
