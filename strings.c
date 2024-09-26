#include "monty.h"

/**
 * print_char_node - Prints the ASCII value at the top of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_char_node(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		char_stack_error(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		char_stack_error(10, line_number);

	printf("%c\n", ascii);
}

/**
 * print_string_nodes - Prints a string formed by elements in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void print_string_nodes(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;

		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotate_left - Rotates the top element of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void rotate_left(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotate_right - Rotates the bottom element of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing
 * rotate_right - Rotates the bottom element of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void rotate_right(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}

