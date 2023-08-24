#ifndef MONTY_H
#define MONTY_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>


#define INSTRUCTIONS \
	{ \
		{"push", push},	\
		{"pall", pall},	\
		{"pint", pint},	\
		{"div", _div},	\
		{"mul", _mul},	\
		{"pop", pop}, \
		{"swap", swap}, \
		{"add", add}, \
		{NULL, NULL}	\
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


extern help_t global;


/********************************************************/
void opcode(stack_t **stack, char *str, unsigned int line_cnt);

void pint(stack_t **stack, unsigned int line_cnt);
void push(stack_t **stack, unsigned int line_cnt);

void _div(stack_t **stack, unsigned int line_cnt);
void _mul(stack_t **stack, unsigned int line_cnt);
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)));
void pop(stack_t **stack, unsigned int line_cnt);
void swap(stack_t **stack, unsigned int line_cnt);
void add(stack_t **stack, unsigned int line_cnt);

/******************** errors_and_free.c **********************/
void file_err(char *argv);
void err_usage(void);
void free_stack(stack_t *stack);

/******************************* utils file **************************/
stack_t *queue_node(stack_t **stack, const int n);
stack_t *add_node(stack_t **stack, const int n);
size_t print_stack(stack_t *stack);
int is_digit(char *string);

#endif /* MONTY_H */
