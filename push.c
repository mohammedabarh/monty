#include "monty.h"

void push(stack_t **stack, unsigned int line_number) {
    char *arg = strtok(NULL, " \n");
    if (arg == NULL || !is_integer(arg)) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    int n = atoi(arg);
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->next = *stack;
    new_node->prev = NULL;
    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}
