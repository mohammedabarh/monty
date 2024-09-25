#include "monty.h"

void pall(stack_t **stack, unsigned int line_number) {
    stack_t *tmp = *stack;
    while (tmp != NULL) {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
