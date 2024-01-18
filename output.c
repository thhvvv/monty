#include "monty.h"

/**
 * f_printstring - Print string starting at top of stack,
 * followed by a new line.
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return value.
 */
void f_printstr(stack_t **head, unsigned int counter)
{
	stack_t *top;
	(void)counter;

	top = *head;
	while (top)
	{
		if (top->n > 127 || top->n <= 0)
		{
			break;
		}
		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
}

#include "monty.h"

/**
 * f_rotateleft - Rotates the stack to the top.
 * @head: Pointer to the stack head.
 * @counter: Line number (unused).
 * Return: No return value.
 */
void f_rotateleft(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	aux = (*head)->next;
	aux->prev = NULL;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
