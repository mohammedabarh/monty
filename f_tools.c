#include "monty.h"

/**
 * process_file - Processes the Monty byte code file
 * @filename: Name of the file to process
 */
void process_file(char *filename)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_element_t *stack = NULL;

    file = fopen(filename, "r");
    if (file == NULL)
        file_error(filename);

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        execute_instruction(line, &stack, line_number);
    }

    free(line);
    fclose(file);
    free_stack(stack);
}

/**
 * tokenize_line - Tokenizes a line into words
 * @line: The line to tokenize
 *
 * Return: An array of strings (words)
 */
char **tokenize_line(char *line)
{
    char **tokens = NULL;
    char *token;
    int i = 0;

    tokens = malloc(sizeof(char *) * 3);
    if (!tokens)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \n\t");
    while (token && i < 2)
    {
        tokens[i] = token;
        token = strtok(NULL, " \n\t");
        i++;
    }
    tokens[i] = NULL;

    return tokens;
}

/**
 * execute_instruction - Executes a single instruction
 * @line: The line containing the instruction
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void execute_instruction(char *line, stack_element_t **stack, unsigned int line_number)
{
    char **tokens;
    int i;
    instruction_t instructions[] = {
        {"push", push_element},
        {"pall", print_all},
        {"pint", print_top_element},
        {"pop", pop_element},
        {"swap", swap_top_two},
        {"add", add_top_two},
        {"nop", NULL},
        {NULL, NULL}
    };

    tokens = tokenize_line(line);
    if (tokens[0] == NULL || tokens[0][0] == '#')
    {
        free(tokens);
        return;
    }

    for (i = 0; instructions[i].opcode; i++)
    {
        if (strcmp(tokens[0], instructions[i].opcode) == 0)
        {
            if (strcmp(tokens[0], "push") == 0)
                push_element(stack, line_number);
            else if (instructions[i].f)
                instructions[i].f(stack, line_number);
            free(tokens);
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
    free(tokens);
    exit(EXIT_FAILURE);
}

/**
 * free_stack - Frees a stack
 * @stack: Pointer to the top of the stack
 */
void free_stack(stack_element_t *stack)
{
    stack_element_t *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
