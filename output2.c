#include "monty.h"
/**
 * pstr - prints string starting at top of the stack
 * @stack: pointer to stack
 * @line_cnt: number of lines
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = *stack;

	(void)line_cnt;

	while (tmp)
	{
		if (tmp->n >= 0 && tmp->n >= 127)
			fprintf(stdout, "%c", tmp->n);
		else
			break;
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates stack to the top
 * @stack: pointer to the stack
 * @line_cnt: number of lines
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = *stack;
	int tmp_n;

	(void)line_cnt;

	if (*stack &&
