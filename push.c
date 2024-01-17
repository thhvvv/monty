#include "monty.h"
/**
 * push - pushes element to stack
 * @stack: stack given by main
 * @line_cnt: number of lines
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: Usage: push integer\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.srgument)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
}
