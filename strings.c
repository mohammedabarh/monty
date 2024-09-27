#include "monty.h"

/**
 * display_char - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void display_char(stack_t **stack, unsigned int line_number)
{
    int ascii_value;

    if (stack == NULL || *stack == NULL)
        handle_string_error(11, line_number);

    ascii_value = (*stack)->n;
    if (ascii_value < 0 || ascii_value > 127)
        handle_string_error(10, line_number);
    
    printf("%c\n", ascii_value);
}

/**
 * display_string - Prints a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void display_string(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    int ascii_value;
    stack_t *temp_node;

    if (stack == NULL || *stack == NULL)
    {
        printf("\n");
        return;
    }

    temp_node = *stack;
    while (temp_node != NULL)
    {
        ascii_value = temp_node->n;
        if (ascii_value <= 0 || ascii_value > 127)
            break;
        printf("%c", ascii_value);
        temp_node = temp_node->next;
    }
    printf("\n");
}

/**
 * rotate_left - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void rotate_left(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    stack_t *temp_node;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    temp_node = *stack;
    while (temp_node->next != NULL)
        temp_node = temp_node->next;

    temp_node->next = *stack;
    (*stack)->prev = temp_node;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}

/**
 * rotate_right - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void rotate_right(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
    stack_t *temp_node;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    temp_node = *stack;
    while (temp_node->next != NULL)
        temp_node = temp_node->next;

    temp_node->next = *stack;
    temp_node->prev->next = NULL;
    temp_node->prev = NULL;
    (*stack)->prev = temp_node;
    (*stack) = temp_node;
}
