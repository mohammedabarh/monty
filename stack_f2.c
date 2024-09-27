#include "monty.h"

/**
 * no_operation - Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void no_operation(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * swap_stack_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void swap_stack_nodes(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        handle_more_error(8, line_number, "swap");
    
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *stack;
    
    tmp->next = *stack;
    (*stack)->prev = tmp;
    tmp->prev = NULL;
    *stack = tmp;
}

/**
 * add_stack_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void add_stack_nodes(stack_t **stack, unsigned int line_number)
{
    int sum;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        handle_more_error(8, line_number, "add");

    (*stack) = (*stack)->next;
    sum = (*stack)->n + (*stack)->prev->n;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * subtract_stack_nodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void subtract_stack_nodes(stack_t **stack, unsigned int line_number)
{
    int difference;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        handle_more_error(8, line_number, "sub");

    (*stack) = (*stack)->next;
    difference = (*stack)->n - (*stack)->prev->n;
    (*stack)->n = difference;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * divide_stack_nodes - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void divide_stack_nodes(stack_t **stack, unsigned int line_number)
{
    int quotient;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        handle_more_error(8, line_number, "div");

    if ((*stack)->n == 0)
        handle_more_error(9, line_number);

    (*stack) = (*stack)->next;
    quotient = (*stack)->n / (*stack)->prev->n;
    (*stack)->n = quotient;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
