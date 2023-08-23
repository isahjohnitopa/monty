#include "monty.h"

/**
 * print_stack - function that prints the contents of a stack_t stack
 * @stack: the stack head
 *
 * Return: number of elements of the list
 */
size_t print_stack(const stack_t *stack)
{
	size_t c = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		c++;
	}

	return (c);
}


/**
 * add_node - function that adds a node to the start of a stack_t stack
 * @stack: the stack head
 * @n: number for the new node
 *
 * Return: Returns newly created node, if creation fails - NULL
 */
stack_t *add_node(stack_t **stack, const in n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}

	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	
	if (*stack)
		(*stack)->prev = new;

	*stack = new;
	return (new);
}
