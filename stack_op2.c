#include "monty.h"

/**
 * swap_it - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the Monty bytecode file.
 */
void swap_it(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add_it - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the Monty bytecode file.
 */
void add_it(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop_do - Doesn't do anything.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the Monty bytecode file.
 */
void nop_do(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
