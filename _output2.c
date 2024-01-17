#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * mod - computes the remainder of the division
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}

	result = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pchar - prints the int at the top of the stack as char
 * @stack: stack given by main
 * @line_cnt: ammount of lines
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	printf("%c\n", (*stack)->n);
}
