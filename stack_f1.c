#include "monty.h"

/**
 * push_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
 */
void push_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * display_stack - Prints all elements in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void display_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * remove_top - Removes the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void remove_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		handle_stack_error(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
}

/**
 * show_top - Prints the value at the top of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void show_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		handle_stack_error(6, line_number);

	printf("%d\n", (*stack)->n);
}

