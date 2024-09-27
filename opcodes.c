#include "monty.h"

/* Push function to add a value to the stack */
void push(stack_t **stack, unsigned int line_number, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
        handle_error("Error: malloc failed", line_number);

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    
    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/* Pall function to print all values on the stack */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

