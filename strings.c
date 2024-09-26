#include "monty.h"

/**
 * display_char - Prints the ASCII character.
 * @stack: Pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void display_char(stack_t **stack, unsigned int line_number)
{
    int ascii_value;

    if (!stack || !*stack)
        handle_string_errors(11, line_number);

    ascii_value = (*stack)->n;
    if (ascii_value < 0 || ascii_value > 127)
        handle_string_errors(10, line_number);
    
    printf("%c\n", ascii_value);
}

/**
 * display_string - Prints a string from the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void display_string(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    stack_t *temp = *stack;
    int ascii_value;

    if (!stack || !*stack)
    {
        printf("\n");
        return;
    }

    while (temp)
    {
        ascii_value = temp->n;
        if (ascii_value <= 0 || ascii_value > 127)
            break;
        printf("%c", ascii_value);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * rotate_left - Rotates the first node to the end of the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void rotate_left(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
        return;

    temp = *stack;
    while (temp->next)
        temp = temp->next;

    temp->next = *stack;
    (*stack)->prev = temp;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}

/**
 * rotate_right - Moves the last node to the top of the stack.
 * @stack: Pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void rotate_right(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
        return;

    temp = *stack;

    while (temp->next)
        temp = temp->next;

    temp->next = *stack;
    temp->prev->next = NULL;
    temp->prev = NULL;
    (*stack)->prev = temp;
    *stack = temp;
}
