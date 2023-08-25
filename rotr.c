#include "monty.h"


/**
 * rotr - function that rotates the last node of a stack_t stack
 * @stack: the stack head
 * @line_cnt: the line count
 *
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_cnt)
{
	stack_t *buttom, *top;

	(void) line_cnt;
	if (!stack || !*stack || !(*stack)->next)
		return;

	buttom = *stack;

	while (buttom->next)
		buttom = buttom->next;

	top = buttom->prev;
	buttom->next = *stack;
	buttom->prev = NULL;
	top->next = NULL;
	(*stack)->prev = buttom;
	*stack = buttom;
}
