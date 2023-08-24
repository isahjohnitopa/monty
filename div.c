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
	int divisor = (*stack)->n;
	int divident = (*stack)->next->n;
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	result = divident / divisor;

	if (divisor < 0 && divident % divisor != 0)
		result -= 1;

	(*stack)->next->n = result;
	pop(stack, line_cnt);
}
