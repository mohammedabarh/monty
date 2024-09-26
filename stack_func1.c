#include "monty.h"

void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node;
    int value;

    if (!arg || !isdigit(*arg))
        more_err(line_number, "L<line_number>: usage: push integer");

    value = atoi(arg);
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
        more_err(line_number, "Error: malloc failed");

    new_node->n = value;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number; // Unused variable

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void pint(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
        more_err(line_number, "L<line_number>: can't pint, stack empty");

    printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack)
        more_err(line_number, "L<line_number>: can't pop an empty stack");

    temp = *stack;
    *stack = (*stack)->next;

    if (*stack)
        (*stack)->prev = NULL;

    free(temp);
}

void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *first, *second;

    if (!stack || !*stack || !(*stack)->next)
        more_err(line_number, "L<line_number>: can't swap, stack too short");

    first = *stack;
    second = first->next;

    first->next = second->next;
    if (first->next)
        first->next->prev = first;

    second->prev = NULL;
    second->next = first;
    first->prev = second;

    *stack = second;
}
