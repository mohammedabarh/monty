#include "monty.h"

/**
 * mul_nodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int product;

	if (!stack || !*stack || !(*stack)->next)
		handle_additional_errors(8, line_number, "mul");

	(*stack) = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - Computes the modulus of the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (!stack || !*stack || !(*stack)->next)
		handle_additional_errors(8, line_number, "mod");

	if ((*stack)->n == 0)
		handle_additional_errors(9, line_number);
	(*stack) = (*stack)->next;
	remainder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = remainder;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
