#include "monty.h"

/**
 * _mul - Function that multiplies the second and the top element of the stack
 * @stack: The stack given by the main file
 * @line_cnt: The line counter
 *
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_cnt);
}
