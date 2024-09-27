#include "monty.h"

/**
 * multiply_stack_nodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void multiply_stack_nodes(stack_t **stack, unsigned int line_number)
{
    int product;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        handle_more_error(8, line_number, "mul");

    (*stack) = (*stack)->next;
    product = (*stack)->n * (*stack)->prev->n;
    (*stack)->n = product;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * modulate_stack_nodes - Computes the modulus of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void modulate_stack_nodes(stack_t **stack, unsigned int line_number)
{
    int remainder;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        handle_more_error(8, line_number, "mod");

    if ((*stack)->n == 0)
        handle_more_error(9, line_number);

    (*stack) = (*stack)->next;
    remainder = (*stack)->n % (*stack)->prev->n;
    (*stack)->n = remainder;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
