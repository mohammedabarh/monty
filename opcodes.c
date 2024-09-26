#include "monty.h"

/**
 * multiply_nodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void multiply_nodes(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
        handle_specific_errors(8, line_number, "mul");

    (*stack) = (*stack)->next;
    (*stack)->n *= (*stack)->prev->n;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * modulate_nodes - Calculates the modulus of the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void modulate_nodes(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
        handle_specific_errors(8, line_number, "mod");

    if ((*stack)->n == 0)
        handle_specific_errors(9, line_number);
    
    (*stack) = (*stack)->next;
    (*stack)->n %= (*stack)->prev->n;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
