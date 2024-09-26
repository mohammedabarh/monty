#include "monty.h"

void mod(stack_t **stack, unsigned int line_number)
{
    int remainder;

    if (!stack || !*stack || !(*stack)->next)
        more_err(line_number, "L<line_number>: can't mod, stack too short");

    if ((*stack)->n == 0)
        more_err(line_number, "L<line_number>: division by zero");

    remainder = (*stack)->next->n % (*stack)->n;
    pop(stack, line_number);
    (*stack)->n = remainder;
}

void pchar(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
        more_err(line_number, "L<line_number>: can't pchar, stack empty");

    if ((*stack)->n < 0 || (*stack)->n > 127)
        more_err(line_number, "L<line_number>: can't pchar, value out of range");

    printf("%c\n", (*stack)->n);
}

void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number; // Unused variable

    while (current && current->n > 0 && current->n < 128)
    {
        printf("%c", current->n);
        current = current->next;
    }
    printf("\n");
}

void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *top;

    if (!stack || !*stack || !(*stack)->next)
        return; // No action needed if there's less than two elements

    top = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;

    top->next = NULL;
    stack_t *last = *stack;

    while (last->next != NULL)
        last = last->next;

    last->next = top;
    top->prev = last;
}

void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *last;

    if (!stack || !*stack || !(*stack)->next)
        return; // No action needed if there's less than two elements

    last = *stack;

    while (last->next != NULL)
        last = last->next;

    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
    last->prev->next = NULL;
    last->prev = NULL;
}
