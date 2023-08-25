#include "monty.h"
#include <ctype.h>

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
	if (!isascii((*stack)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
