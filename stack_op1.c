#include "monty.h"

/**
 * push_it - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @value: Integer value to be pushed onto the stack.
 */
void push_it(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall_it - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the Monty bytecode file.
 */
void pall_it(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint_it - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the Monty bytecode file.
 */
void pint_it(stack_t **stack, int value, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop_it - Removes the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the Monty bytecode file.
 */
void pop_it(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
