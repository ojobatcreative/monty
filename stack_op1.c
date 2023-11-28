#include "monty.h"
/**
 * push_it - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void push_it(stack_t **head, unsigned int counter)
{
	int n, tj = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			tj++;
		for (; bus.arg[tj] != '\0'; tj++)
		{
			if (bus.arg[tj] > 57 || bus.arg[tj] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * pall_it - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void pall_it(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
