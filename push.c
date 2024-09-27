#include "monty.h"
/**
 * op_push - adds a new node at the beginning of the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void op_push(stack_t **stack, unsigned int line_number)
{
	int value, i = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				flag = 1; 
        }
		if (flag == 1)
		{ 
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE); 
        }
    }
	else
	{ 
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE); 
    }
	value = atoi(bus.arg);
	if (bus.lifi == 0)
		node_add(stack, value);
	else
		addqueue(stack, value);
}

