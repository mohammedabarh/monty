#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
    int sum;

    if (!stack || !*stack || !(*stack)->next)
        more_err(line_number, "L<line_number>: can't add, stack too short");

    sum = (*stack)->n + (*stack)->next->n;
    pop(stack, line_number);
    (*stack)->n = sum;
}

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

void sub(stack_t **stack, unsigned int line_number)
{
    int difference;

    if (!stack || !*stack || !(*stack)->next)
        more_err(line_number, "L<line_number>: can't sub, stack too short");

    difference = (*stack)->next->n - (*stack)->n;
    pop(stack, line_number);
    (*stack)->n = difference;
}

void div_func(stack_t **stack, unsigned int line_number)
{
    int quotient;

    if (!stack || !*stack || !(*stack)->next)
        more_err(line_number, "L<line_number>: can't div, stack too short");

    if ((*stack)->n == 0)
        more_err(line_number, "L<line_number>: division by zero");

    quotient = (*stack)->next->n / (*stack)->n;
    pop(stack, line_number);
    (*stack)->n = quotient;
}

void mul(stack_t **stack, unsigned int line_number)
{
    int product;

    if (!stack || !*stack || !(*stack)->next)
        more_err(line_number, "L<line_number>: can't mul, stack too short");

    product = (*stack)->next->n * (*stack)->n;
    pop(stack, line_number);
    (*stack)->n = product;
}
