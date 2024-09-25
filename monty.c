#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 1000
#define MAX_LINE_LENGTH 1000

typedef struct stack_s {
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s {
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *stack = NULL;
int stack_format = 0; // 0 for stack (LIFO), 1 for queue (FIFO)

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack_op(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

void free_stack(stack_t *stack);
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number);

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    unsigned int line_number = 0;
    char *opcode;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        opcode = strtok(line, " \t\n");
        if (opcode && opcode[0] != '#') {
            execute_instruction(opcode, &stack, line_number);
        }
    }

    fclose(file);
    free_stack(stack);
    return 0;
}

void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number) {
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {"sub", sub},
        {"div", div_op},
        {"mul", mul},
        {"mod", mod},
        {"pchar", pchar},
        {"pstr", pstr},
        {"rotl", rotl},
        {"rotr", rotr},
        {"stack", stack_op},
        {"queue", queue},
        {NULL, NULL}
    };

    int i;
    for (i = 0; instructions[i].opcode; i++) {
        if (strcmp(opcode, instructions[i].opcode) == 0) {
            instructions[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

// Implement the opcode functions here
void push(stack_t **stack, unsigned int line_number) {
    char *arg = strtok(NULL, " \t\n");
    int n, i;

    if (!arg) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    for (i = 0; arg[i]; i++) {
        if (arg[i] == '-' && i == 0)
            continue;
        if (!isdigit(arg[i])) {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    n = atoi(arg);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;

    if (stack_format == 0) { // Stack (LIFO)
        new_node->next = *stack;
        if (*stack)
            (*stack)->prev = new_node;
        *stack = new_node;
    } else { // Queue (FIFO)
        new_node->next = NULL;
        if (!*stack) {
            *stack = new_node;
        } else {
            stack_t *temp = *stack;
            while (temp->next)
                temp = temp->next;
            temp->next = new_node;
            new_node->prev = temp;
        }
    }
}

void pall(stack_t **stack, unsigned int line_number) {
    stack_t *temp = *stack;
    (void)line_number;

    while (temp) {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

void pint(stack_t **stack, unsigned int line_number) {
    if (!*stack) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number) {
    stack_t *temp;

    if (!*stack) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(temp);
}

void swap(stack_t **stack, unsigned int line_number) {
    int temp;

    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

void add(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}

void nop(stack_t **stack, unsigned int line_number) {
    (void)stack;
    (void)line_number;
}

void sub(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}

void div_op(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0) {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    pop(stack, line_number);
}

void mul(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    pop(stack, line_number);
}

void mod(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0) {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n %= (*stack)->n;
    pop(stack, line_number);
}

void pchar(stack_t **stack, unsigned int line_number) {
    if (!*stack) {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127) {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
}

void pstr(stack_t **stack, unsigned int line_number) {
    stack_t *temp = *stack;
    (void)line_number;

    while (temp && temp->n > 0 && temp->n <= 127) {
        printf("%c", temp->n);
        temp = temp->next;
    }
    printf("\n");
}

void rotl(stack_t **stack, unsigned int line_number) {
    stack_t *temp;
    (void)line_number;

    if (*stack && (*stack)->next) {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        temp->next = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        temp->next->next = NULL;
        temp->next->prev = temp;
    }
}

void rotr(stack_t **stack, unsigned int line_number) {
    stack_t *temp;
    (void)line_number;

    if (*stack && (*stack)->next) {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        temp->next = *stack;
        temp->prev->next = NULL;
        temp->prev = NULL;
        (*stack)->prev = temp;
        *stack = temp;
    }
}

void stack_op(stack_t **stack, unsigned int line_number) {
    (void)stack;
    (void)line_number;
    stack_format = 0;
}

void queue(stack_t **stack, unsigned int line_number) {
    (void)stack;
    (void)line_number;
    stack_format = 1;
}

void free_stack(stack_t *stack) {
    stack_t *temp;

    while (stack) {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
