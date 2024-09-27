#include "monty.h"
/**
 * op_pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: stack head
 * @line_number: not used
 * Return: no return
*/
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

