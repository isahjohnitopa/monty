#include "monty.h"

/**
 * print_stack - function that prints the contents of a stack_t stack
 * @stack: the stack head
 *
 * Return: number of elements of the list
 */
size_t print_stack(stack_t *stack)
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
stack_t *add_node(stack_t **stack, const int n)
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


/**
 * queue_node - add a node to a stack_t stack in queue_node
 * @stack: the stack head
 * @n: number of the node
 *
 * Return: Returns the newly created node, if memory allocation fails - NULL
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new, *current = *stack;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}

	return (new);
}


/**
 * is_digit - function that checks if a string is a digit
 * @string: string to check
 *
 * Return: 1 if is digit, 0 otherwise
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;

	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
