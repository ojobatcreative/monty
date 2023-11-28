#include "monty.h"

/**
 * ex_op - Executes the given op.
 * @stack: Double pointer to the head of the stack.
 * @op: Opcode to be executed.
 * @value: Integer value (if any) associated with the opcode.
 * @line_number: Line number of the Monty bytecode file.
 */

void ex_op(stack_t **stack, char *op, int value, unsigned int line_number)
{
	typedef struct
	{
		const char *name;
		void (*function)(stack_t **, unsigned int);
	}

	OpMapping;

	OpMapping op[] =
	{
		{"push", push_it},
		{"pall", pall_it},
		{"pint", pint_it},
		{"pop", pop_it},
		{"swap", swap_it},
		{"add", add_it},
		{"nop", nop_do},
		{"mul", mul_it},
		{"mod", mod_it},
		{"rotl", rotl_it},
		{"queue", queue_it},
	};

	size_t num_ops sizeof(ops) / sizeof(ops[0]);

	for (size_t i = 0; i < num_ops; ++i)
	{
		if (strcmp(op, ops[i].name) == 0)
		{
			ops[i].function(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
    exit(EXIT_FAILURE);
}

