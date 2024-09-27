#include "monty.h"
/**
* opcode_execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int opcode_execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", stack_push}, {"pall", stack_pall}, {"pint", stack_pint},
				{"pop", stack_pop},
				{"swap", stack_swap},
				{"add", stack_add},
				{"nop", stack_nop},
				{"sub", stack_sub},
				{"div", stack_div},
				{"mul", stack_mul},
				{"mod", stack_mod},
				{"pchar", stack_pchar},
				{"pstr", stack_pstr},
				{"rotl", stack_rotl},
				{"rotr", stack_rotr},
				{"queue", stack_queue},
				{"stack", stack_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ 
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); 
    }
	return (1);
}

