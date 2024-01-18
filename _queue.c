#include "monty.h"
/**
 * f_switch_to_queue - Switches the data structure to queue mode.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_switch_to_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 *enqueue - Adds a node to the tail of the stack.
 *@n: New value.
 * @head: Pointer to the stack head.
 * Return: No return value.
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
