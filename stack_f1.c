#include "monty.h"

/**
 * push_element - Adds an element to the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void push_element(stack_element_t **stack, unsigned int line_number)
{
    stack_element_t *new_element;
    char *arg = strtok(NULL, " \n\t");
    int value;

    if (!arg || !isdigit(*arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    new_element = malloc(sizeof(stack_element_t));
    if (!new_element)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_element->value = value;
    new_element->prev = NULL;
    new_element->next = *stack;

    if (*stack)
        (*stack)->prev = new_element;
    *stack = new_element;
}

/**
 * print_all - Prints all elements in the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file (unused)
 */
void print_all(stack_element_t **stack, unsigned int line_number)
{
    stack_element_t *current = *stack;
    (void)line_number;

    while (current)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

/**
 * pop_element - Removes the top element from the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void pop_element(stack_element_t **stack, unsigned int line_number)
{
    stack_element_t *temp;

    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(temp);
}

/**
 * print_top_element - Prints the value at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void print_top_element(stack_element_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->value);
}
