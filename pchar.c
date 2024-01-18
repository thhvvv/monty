#include "monty.h"
/**
 * f_printchar - will print the top character on the stack
 * followed by a new line
 * @head: stack head pointer
 * @counter: Line number
 * Return: No Return Value
 */
void f_printchar(stack_t **head, unsigned int counter)
{
	stack_t *top;

	top = *head;
	if (!top)
	{
		fprintf(stderr, "L%d: can't print char, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: can't print char, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}
