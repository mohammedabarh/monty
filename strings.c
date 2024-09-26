#include "monty.h"

/**
 * print_char_top - Prints the char at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void print_char_top(stack_element_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->value < 0 || (*stack)->value > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->value);
}

/**
 * print_string - Prints the string starting at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 */
void print_string(stack_element_t **stack, unsigned int line_number)
{
    stack_element_t *current = *stack;
    (void)line_number;

    while (current && current->value > 0 && current->value <= 127)
    {
        printf("%c", current->value);
        current = current->next;
    }
    printf("\n");
}
