#include "monty.h"

int is_integer(char *arg)
{
    if (arg == NULL)
        return 0;
    for (int i = 0; arg[i] != '\0'; i++)
    {
        if (!isdigit(arg[i]) && !(i == 0 && arg[i] == '-'))
            return 0;
    }
    return 1;
}

void free_stack(stack_t **stack)
{
    stack_t *tmp;
    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}
