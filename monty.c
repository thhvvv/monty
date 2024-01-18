#include "monty.h"

/**
 * f_swap_top_two - Swaps the positions of the top two elements in the stack.
 * @head: Pointer to the stack head.
 * @counter: Line number
 * Return: No return value.
 */

void f_swap_top_two(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;

	while (h)
	{
		h = h->next;
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

	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;

}
