#include "monty.h"

/**
 * mod - computes the remainder of the division
 * @stack: pointer to the head of the stack
 * @line_cnt: the line counter
 *
 * Return: nothing
 */
void _mod(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}

	((*stack)->next->n) %= ((*stack)->n);
	pop(stack, line_cnt);
}
