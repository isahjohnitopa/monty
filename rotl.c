#include "monty.h"

/**
 * rotl - function that rotl the first element to last element of the stack
 * @stack: pointer to the stack head
 * @line_cnt: the line counter
 *
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_cnt)
{
	stack_t *left, *right;

	(void) line_cnt;
	left = right = *stack;
	if (!stack || !*stack || !(*stack)->next)
		return;

	while (right->next) /* move the right pointer to the last node */
		right = right->next;
	right->next = left; /* a circle infinite linked list loop */
	left->prev = right;
	*stack = left->next; /* so we cut the link between 0 and 1 element */
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
