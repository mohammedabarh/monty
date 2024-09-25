#include "monty.h"

int queue_mode = 0;

instruction_t opcodes[] = {
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
    {"stack", stack_mode},
    {"queue", queue_mode_op},
    {NULL, NULL}
};

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    char *opcode, *arg;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
            continue;

        arg = strtok(NULL, " \t\n");

        for (int i = 0; opcodes[i].opcode; i++)
        {
            if (strcmp(opcode, opcodes[i].opcode) == 0)
            {
                if (strcmp(opcode, "push") == 0)
                {
                    if (arg == NULL || !is_number(arg))
                    {
                        fprintf(stderr, "L%d: usage: push integer\n", line_number);
                        free_stack(stack);
                        fclose(file);
                        free(line);
                        exit(EXIT_FAILURE);
                    }
                    push(&stack, atoi(arg));
                }
                else
                {
                    opcodes[i].f(&stack, line_number);
                }
                break;
            }
        }
        if (opcodes[i].opcode == NULL)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            free_stack(stack);
            fclose(file);
            free(line);
            exit(EXIT_FAILURE);
        }
    }

    free_stack(stack);
    fclose(file);
    free(line);
    return EXIT_SUCCESS;
}

int is_number(char *str)
{
    if (*str == '-')
        str++;
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

void free_stack(stack_t *stack)
{
    stack_t *temp;
    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
