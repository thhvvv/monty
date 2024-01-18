#include "monty.h"

/**
* execute - executes opcode
* @stack: double pointer to head linked list - stack
* @counter: line counter
* @file: pointer to monty file
* @content: line content
* Return: void
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push_to_stack}, {"pall", f_pall}, {"pint", f_print_top},
				{"pop", f_pop_stack},
				{"swap", f_swap_top_two},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_subtract_top_two},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_printchar},
				{"pstr", f_printstr},
				{"rotl",f_rotateleft},
				{"rotr", f_rotateright},
				{"queue", f_switch_to_queue},
				{"stack", f_switch_to_stack},
				{NULL, NULL}
				};
	unsigned int j = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[j].opcode && op)
	{
		if (strcmp(op, opst[j].opcode) == 0)
		{	opst[j].f(stack, counter);
			return (0);
		}
		j++;
	}
	if (op && opst[j].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
