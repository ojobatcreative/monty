#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
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

void push_it(stack_t **stack, int value);
void pall_it(stack_t **stack, unsigned int line_number);
void pint_it(stack_t **stack, unsigned int line_number);
void pop_it(stack_t **stack, unsigned int line_number);
void swap_it(stack_t **stack, unsigned int line_number);
void add_it(stack_t **stack, unsigned int line_number);
void nop_do(stack_t **stack, unsigned int line_number);

void mul_it(stack_t **head, unsigned int counter);
void mod_it(stack_t **head, unsigned int counter);

void rotl_it(stack_t **head,  __attribute__((unused)) unsigned int counter);
void add_queue(stack_t **head, int n);
void queue_it(stack_t **stack, unsigned int line_number);

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)

#endif /* MONTY_H */

