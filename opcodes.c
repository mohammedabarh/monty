#include "monty.h"

/**
 * multiply_top_two - Multiplies the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void multiply_top_two(stack_element_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->value *= (*stack)->value;
    pop_element(stack, line_number);
}

/**
 * modulo_top_two - Computes the modulo of the second top element by the top element
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void modulo_top_two(stack_element_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->value == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->value %= (*stack)->value;
    pop_element(stack, line_number);
}

/**
 * rotate_left - Rotates the stack to the top
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 */
void rotate_left(stack_element_t **stack, unsigned int line_number)
{
    stack_element_t *last;
    (void)line_number;

    if (*stack && (*stack)->next)
    {
        last = *stack;
        while (last->next)
            last = last->next;

        last->next = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        last->next->next = NULL;
        last->next->prev = last;
    }
}

/**
 * rotate_right - Rotates the stack to the bottom
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 */
void rotate_right(stack_element_t **stack, unsigned int line_number)
{
    stack_element_t *last;
    (void)line_number;

    if (*stack && (*stack)->next)
    {
        last = *stack;
        while (last->next)
            last = last->next;

        last->next = *stack;
        last->prev->next = NULL;
        (*stack)->prev = last;
        *stack = last;
        (*stack)->prev = NULL;
    }
}
