#include "monty.h"
/**
 * op_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int count = 0, result;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = temp->next->n % temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}

