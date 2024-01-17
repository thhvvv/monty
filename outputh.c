#include "monty.h"
/**
 * mod - computes the modulus of top elements of the stack
 * @stack: pointer to stack
 * @line_cnt: number of lines
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = *stack;

	(void)line_cnt;

	if (*stack && (*stack)->next)
	{
		if (tmp->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_cnt);
			exit(EXIT_FAILURE);
		}
		tmp->next->n %= tmp->n;
		*stack = (*stack)->next;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}
}
/**
 * pchar - prints the char at the top of stack
 * @stack: pointer to stack
 * @line_cnt: number of lines
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_cnt)
{
	(void)line_cnt;

	if (*stack)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
			fprint(stdout, "%c\n", (*stack)->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt;
					exit(EXIT_FAILURE);
					}
					}
					else
					{
					fprintf(stderr, "L%d: can't pchar, stack empty\n", line_cnt);
					exit(EXIT_FAILURE);
					}
					}
