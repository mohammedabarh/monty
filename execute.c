#include "monty.h"
/**
* run_opcode - executes the opcode
* @stack: head linked list - stack
* @line_number: line_counter
* @file: pointer to monty file
* @content: line content
* Return: no return
*/
int run_opcode(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t ops[] = {
				{"push", op_push}, {"pall", op_pall}, {"pint", op_pint},
				{"pop", op_pop},
				{"swap", op_swap},
				{"add", op_add},
				{"nop", op_nop},
				{"sub", op_sub},
				{"div", op_div},
				{"mul", op_mul},
				{"mod", op_mod},
				{"pchar", op_pchar},
				{"pstr", op_pstr},
				{"rotl", op_rotl},
				{"rotr", op_rotr},
				{"queue", op_queue},
				{"stack", op_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (ops[i].opcode && opcode)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{	ops[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opcode && ops[i].opcode == NULL)
	{ 
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); 
    }
	return (1);
}

