#include "monty.h"

/**
 * add_to_stack - Pushes a new node onto the stack.
 * @new_node: Pointer to the node to be added.
 * @line_num: The line number of the command.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int line_num)
{
	stack_t *previous;

	if (!new_node || !*new_node)
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *new_node;
		return;
	}
	previous = head;
	head = *new_node;
	head->next = previous;
	previous->prev = head;
}

/**
 * print_stack - Outputs all elements in the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	if (!stack)
		exit(EXIT_FAILURE);
	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop_top - Removes the top element from the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!stack || !*stack)
		handle_additional_errors(7, line_number);

	current = *stack;
	*stack = current->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(current);
}

/**
 * print_top - Displays the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
		handle_additional_errors(6, line_number);
	printf("%d\n", (*stack)->n);
}
