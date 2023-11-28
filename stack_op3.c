#include "monty.h"
/**
 * add_it - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void add_it(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	th = *head;
	aux = th->n + th->next->n;
	th->next->n = aux;
	*head = th->next;
	free(th);
}


#include "monty.h"
/**
  *nop_do- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void nop_do(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
