#include "monty.h"

/**
 * push - Push an element to the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");
    int value;

    if (!arg || !is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    /* Rest of the push function remains the same */
    /* ... */
}



/**
 * pall - Print all values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number;

    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

/**
 * pint - Print the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pop - Remove the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(temp);
}

/**
 * swap - Swap the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

/**
 * add - Add the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}

/**
 * nop - Do nothing
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * sub - Subtract the top element from the second top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void sub(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}

/**
 * div_op - Divide the second top element by the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void div_op(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    pop(stack, line_number);
}

/**
 * mul - Multiply the second top element with the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void mul(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    pop(stack, line_number);
}

/**
 * mod - Compute the rest of the division of the second top element by the top element
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void mod(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n %= (*stack)->n;
    pop(stack, line_number);
}

/**
 * pchar - Print the char at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
}

/**
 * pstr - Print the string starting at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number;

    while (temp && temp->n > 0 && temp->n <= 127)
    {
        printf("%c", temp->n);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * rotl - Rotate the stack to the top
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *last;
    (void)line_number;

    if (*stack && (*stack)->next)
    {
        temp = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;

        last = *stack;
        while (last->next)
            last = last->next;

        last->next = temp;
        temp->prev = last;
        temp->next = NULL;
    }
}

/**
 * rotr - Rotate the stack to the bottom
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *last;
    (void)line_number;

    if (*stack && (*stack)->next)
    {
        last = *stack;
        while (last->next)
            last = last->next;

        temp = last->prev;
        temp->next = NULL;

        last->prev = NULL;
        last->next = *stack;
        (*stack)->prev = last;
        *stack = last;
    }
}

/**
 * stack_op - Set the format of the data to a stack (LIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    stack_mode = 1;
}

/**
 * queue - Set the format of the data to a queue (FIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void queue(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    stack_mode = 0;
}
