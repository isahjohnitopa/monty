#include "monty.h"

/**
 * pchar - Function that prints the integer at the top as char
 * @stack: the pointer to the top of the stack
 * @line_cnt: the line counter 
 *
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n < 0) || ((*stack)->n > 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
