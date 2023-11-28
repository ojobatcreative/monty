#include "monty.h"

/**
 * pint_it - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pint_it(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


/**
 * pop_it - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pop_it(stack_t **head, unsigned int counter)
{
	stack_t *th;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	th = *head;
	*head = th->next;
	free(th);
}

/**
 * swap_it - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void swap_it(stack_t **head, unsigned int counter)
{
	stack_t *th;
	int len = 0, aux;

	th = *head;
	while (th)
	{
		th = th->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	th = *head;
	aux = th->n;
	th->n = th->next->n;
	th->next->n = aux;
}
