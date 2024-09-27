#include "monty.h"
/**
 * op_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

