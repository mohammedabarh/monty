#include "monty.h"
/**
 * op_queue - sets the format of the data to a queue (FIFO)
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifi = 1;
}

/**
 * addqueue - adds a new node at the end of the stack
 * @value: new value
 * @stack: head of the stack
 * Return: no return
*/
void addqueue(stack_t **stack, int value)
{
	stack_t *new_node, *temp;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = value;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}

