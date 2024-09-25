#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n");
    if (arg == NULL || !is_integer(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = atoi(arg);
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *tmp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(tmp);
}

void swap(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *first = *stack;
    stack_t *second = first->next;

    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *stack = second;
}

void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *first = *stack;
    stack_t *second = first->next;

    first->n += second->n;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    
    free(second);
}

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

void sub(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *first = *stack;
    stack_t *second = first->next;

    first->n -= second->n;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    
    free(second);
}

void div_op(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *first = *stack;
    stack_t *second = first->next;

    if (second->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    first->n /= second->n;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    
    free(second);
}

void mul(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *first = *stack;
    stack_t *second = first->next;

    first->n *= second->n;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    
    free(second);
}

void mod(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack_t *first = *stack;
    stack_t *second = first->next;

    if (second->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    first->n %= second->n;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    
    free(second);
}

void pchar(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    int ascii = (*stack)->n;
    if (ascii < 0 || ascii > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", ascii);
}

void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    while (current != NULL && current->n > 0 && current->n < 128)
    {
        printf("%c", current->n);
        current = current->next;
    }
    printf("\n");
}

void rotl(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    stack_t *tmp = *stack;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stack;
    (*stack)->prev = tmp;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}

void rotr(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    stack_t *tmp = *stack;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stack;
    (*stack)->prev = tmp;
    *stack = tmp;
    (*stack)->next->prev = NULL;
}
