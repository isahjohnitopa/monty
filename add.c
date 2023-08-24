#include "monty.h"

/**
  *add - functions that adds 2 stack
  * @stack: the stack elements
  * line_cnt: the code line number
  */

void add(stack_t **stack, unsigned int line_cnt)
{
	int results;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	results = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_cnt);
	(*stack)->n = results;
}
