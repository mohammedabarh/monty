#include "monty.h"
/**
 * op_mul - multiplies the second top element of the stack with the top element.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void op_mul(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	result = temp->next->n * temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}

