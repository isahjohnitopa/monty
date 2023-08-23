#include "monty.h"

/**
 * pint - function that prints the value at the top of the stack
 * @stack: ponter to the stack head;
 * @line_cnt: the amount of line
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
