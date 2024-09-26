#include "monty.h"

/**
 * do_nothing - A no-operation function.
 * @stack: Pointer to the stack.
 * @line_number: The line number of the opcode.
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * swap_top_nodes - Swaps the top two nodes of the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void swap_top_nodes(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
        handle_specific_errors(8, line_number, "swap");
    
    temp = (*stack)->next;
    (*stack)->next = temp->next;
    if (temp->next)
        temp->next->prev = *stack;
    temp->next = *stack;
    (*stack)->prev = temp;
    temp->prev = NULL;
    *stack = temp;
}

/**
 * sum_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void sum_nodes(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
        handle_specific_errors(8, line_number, "add");

    (*stack) = (*stack)->next;
    (*stack)->n += (*stack)->prev->n;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * subtract_nodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void subtract_nodes(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
        handle_specific_errors(8, line_number, "sub");

    (*stack) = (*stack)->next;
    (*stack)->n -= (*stack)->prev->n;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * divide_nodes - Divides the top two elements of the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void divide_nodes(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
        handle_specific_errors(8, line_number, "div");

    if ((*stack)->n == 0)
        handle_specific_errors(9, line_number);
    
    (*stack) = (*stack)->next;
    (*stack)->n /= (*stack)->prev->n;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
