#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");
    int n;
    stack_t *new;

    if (!arg || !is_number(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);
    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new->n = n;
    new->prev = NULL;

    if (is_queue)
    {
        stack_t *last = *stack;
        if (last)
        {
            while (last->next)
                last = last->next;
            last->next = new;
            new->prev = last;
        }
        else
            *stack = new;
    }
    else
    {
        new->next = *stack;
        if (*stack)
            (*stack)->prev = new;
        *stack = new;
    }
}

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

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
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}

/**
 * nop - doesn't do anything
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * sub - subtracts the top element from the second top element of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}

/**
 * div_op - divides the second top element by the top element of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void div_op(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    pop(stack, line_number);
}

/**
 * mul - multiplies the second top element with the top element of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    pop(stack, line_number);
}

/**
 * mod - computes the rest of the division of the second top element by the top element
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n %= (*stack)->n;
    pop(stack, line_number);
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (char)(*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    while (current && current->n > 0 && current->n <= 127)
    {
        printf("%c", (char)current->n);
        current = current->next;
    }
    printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *last;
    (void)line_number;

    if (!*stack || !(*stack)->next)
        return;

    last = *stack;
    while (last->next)
        last = last->next;

    last->next = *stack;
    (*stack)->prev = last;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *last;
    (void)line_number;

    if (!*stack || !(*stack)->next)
        return;

    last = *stack;
    while (last->next)
        last = last->next;

    last->next = *stack;
    last->prev->next = NULL;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}

/**
 * stack_mode - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    is_queue = 0;
}

/**
 * queue_mode - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    is_queue = 1;
}
