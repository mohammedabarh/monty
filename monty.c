#include "monty.h"

int is_queue = 0;

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL, *opcode;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    instruction_t instructions[] = {
        {"push", push}, {"pall", pall}, {"pint", pint},
        {"pop", pop}, {"swap", swap}, {"add", add},
        {"nop", nop}, {"sub", sub}, {"div", div_op},
        {"mul", mul}, {"mod", mod}, {"pchar", pchar},
        {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
        {"stack", stack_mode}, {"queue", queue_mode},
        {NULL, NULL}
    };

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
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

        for (int i = 0; instructions[i].opcode; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&stack, line_number);
                break;
            }
        }

        if (instructions[i].opcode == NULL)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            free(line);
            fclose(file);
            free_stack(stack);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return EXIT_SUCCESS;
}

/**
 * free_stack - frees a stack
 * @stack: pointer to the top of the stack
 */
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

/**
 * is_number - checks if a string is a number
 * @str: string to check
 * Return: 1 if number, 0 otherwise
 */
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
