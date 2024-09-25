#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *first = *stack;
    stack_t *second = first->next;
    first->n += second->n;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    free(second);
}

void nop(stack_t **stack, unsigned int line_number)
{
    (void) stack;
    (void) line_number;
}

void sub(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *first = *stack;
    stack_t *second = first->next;
    first->n -= second->n;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    free(second);
}

void div(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *first = *stack;
    stack_t *second = first->next;
    if (second->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    first->n /= second->n;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    free(second);
}
