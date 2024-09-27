#include "monty.h"
/**
 * op_swap - swaps the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int count = 0, value;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	value = temp->n;
	temp->n = temp->next->n;
	temp->next->n = value;
}

