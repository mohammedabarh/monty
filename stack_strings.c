#include "monty.h"

/**
 * print_char - Outputs the ASCII character at the top of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii_val;

	if (!stack || !*stack)
		handle_string_errors(11, line_number);

	ascii_val = (*stack)->n;
	if (ascii_val < 0 || ascii_val > 127)
		handle_string_errors(10, line_number);
	printf("%c\n", ascii_val);
}

/**
 * print_str - Outputs a string represented by the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int ascii_val;
	stack_t *current;

	if (!stack || !*stack)
	{
		printf("\n");
		return;
	}

	current = *stack;
	while (current)
	{
		ascii_val = current->n;
		if (ascii_val <= 0 || ascii_val > 127)
			break;
		printf("%c", ascii_val);
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl - Moves the top element of the stack to the bottom.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *last;

	if (!stack || !*stack || !(*stack)->next)
		return;

	last = *stack;
	while (last->next)
		last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Moves the bottom element of the stack to the top.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the command.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *last;

	if (!stack || !*stack || !(*stack)->next)
		return;

	last = *stack;

	while (last->next)
		last = last->next;

	last->next = *stack;
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack)->prev = last;
	(*stack) = last;
}
