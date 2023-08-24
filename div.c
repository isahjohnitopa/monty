#include "monty.h"


/**
 * _div - Function that divides the next top value by the top value
 * @stack: the stack given by the main func
 * @line_cnt: the line counter
 *
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_cnt);
}
