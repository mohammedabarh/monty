#include "monty.h"

/**
 * push_to_stack - Adds a new node to the top of the stack.
 * @new_node: Pointer to the new node.
 * @line_number: The line number of the opcode.
 */
void push_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int line_number)
{
    stack_t *temp;

    if (!new_node || !*new_node)
        exit(EXIT_FAILURE);
    if (!head)
    {
        head = *new_node;
        return;
    }
    temp = head;
    head = *new_node;
    head->next = temp;
    temp->prev = head;
}

/**
 * display_stack - Outputs all elements in the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the opcode.
 */
void display_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    (void)line_number;
    if (!stack)
        exit(EXIT_FAILURE);
    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

/**
 * remove_top - Removes the top element from the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the opcode.
 */
void remove_top(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack)
        handle_specific_errors(7, line_number);

    temp = *stack;
    *stack = temp->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(temp);
}

/**
 * show_top - Displays the top node of the stack.
 * @stack: Pointer to the stack's top node.
 * @line_number: The line number of the opcode.
 */
void show_top(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
        handle_specific_errors(6, line_number);
    printf("%d\n", (*stack)->n);
}
