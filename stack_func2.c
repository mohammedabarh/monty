#include "monty.h"

/**
 * nop - No operation performed.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_nodes - Exchanges the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *first;

	if (!stack || !*stack || !(*stack)->next)
		handle_additional_errors(8, line_number, "swap");
	first = (*stack)->next;
	(*stack)->next = first->next;
	if (first->next)
		first->next->prev = *stack;
	first->next = *stack;
	(*stack)->prev = first;
	first->prev = NULL;
	*stack = first;
}

/**
 * add_nodes - Sums the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int total;

	if (!stack || !*stack || !(*stack)->next)
		handle_additional_errors(8, line_number, "add");

	(*stack) = (*stack)->next;
	total = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int difference;

	if (!stack || !*stack || !(*stack)->next)
		handle_additional_errors(8, line_number, "sub");

	(*stack) = (*stack)->next;
	difference = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = difference;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - Divides the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (!stack || !*stack || !(*stack)->next)
		handle_additional_errors(8, line_number, "div");

	if ((*stack)->n == 0)
		handle_additional_errors(9, line_number);
	(*stack) = (*stack)->next;
	quotient = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = quotient;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
