#ifndef MONTY_H
#define MONTY_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>


#define _POSIX_C_SOURCE 200809L

#define INSTRUCTIONS
{
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
}

/**
 * struct stack_s - doubly linkedlist representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linkedlist node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - the opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct help_s - argument for the current opcode
 * @data_struct: the stack mode, stack is set to be default
 * @argument: the argument of the string
 *
 * Description: global structure used to pass data arount the function easily
 */
typedef struct help_s
{
	int data_struct;
	char *argument;
} help_t;


help_t global;
int status = 0;


/********************************************************/
void opcode(stack_t **stack, char *str, unsigned int line_cnt);


/******************** errors_and_free.c **********************/
void file_err(char *argv);
void err_usuage(void);
void free_stack(stack_t *stack);

#endif /* MONTY_H */
