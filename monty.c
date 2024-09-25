#include "monty.h"

int stack_mode = 1; /* 1 for stack (LIFO), 0 for queue (FIFO) */

/**
 * main - Monty bytecode interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL, *opcode, *arg;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

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

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
            continue;

        arg = strtok(NULL, " \t\n");
        execute_opcode(&stack, opcode, arg, line_number);
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return (EXIT_SUCCESS);
}

/**
 * execute_opcode - Execute the opcode
 * @stack: Double pointer to the head of the stack
 * @opcode: The opcode to execute
 * @arg: The argument for the opcode (if any)
 * @line_number: The current line number
 */
void execute_opcode(stack_t **stack, char *opcode, char *arg, unsigned int line_number)
{
    instruction_t instructions[] = {
        {"push", push}, {"pall", pall}, {"pint", pint},
        /* ... rest of the instructions ... */
    };
    int i;

    for (i = 0; instructions[i].opcode; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            if (strcmp(opcode, "push") == 0)
            {
                if (arg == NULL || !is_integer(arg))
                {
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }
            }
            instructions[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
/**
 * is_integer - Check if a string is a valid integer
 * @str: The string to check
 * Return: 1 if valid integer, 0 otherwise
 */
int is_integer(const char *str)
{
    if (*str == '-')
        str++;
    if (*str == '\0')
        return 0;
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

/**
 * free_stack - Free the stack
 * @stack: Pointer to the top of the stack
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
