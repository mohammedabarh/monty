#include "monty.h"
/**
  *op_sub- subtracts the top element of the stack from the second top element of the stack
  *@stack: stack head
  *@line_number: line_number
  *Return: no return
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result, nodes;

	temp = *stack;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}

