#include "monty.h"

/**
 * opcode - The function in charge of running builtins
 * @stack: The stack given by main
 * @str: The string to compare
 * @line_cnt: The amount of lines
 *
 * Return: nothing
 */
void opcode(stack_t **stack, char *str, unsigned int line_cnt)
{
	int i = 0;
	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_cnt);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, str);
	exit(EXIT_FAILURE);
}
