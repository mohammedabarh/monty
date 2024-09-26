#include "monty.h"

/**
 * swap_top_two - Swaps the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void swap_top_two(stack_element_t **stack, unsigned int line_number)
{
    int temp;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = temp;
}

/**
 * add_top_two - Adds the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void add_top_two(stack_element_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->value += (*stack)->value;
    pop_element(stack, line_number);
}

/**
 * subtract_top_two - Subtracts the top element from the second top element
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void subtract_top_two(stack_element_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->value -= (*stack)->value;
    pop_element(stack, line_number);
}

/**
 * divide_top_two - Divides the second top element by the top element
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void divide_top_two(stack_element_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->value == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->value /= (*stack)->value;
    pop_element(stack, line_number);
}
