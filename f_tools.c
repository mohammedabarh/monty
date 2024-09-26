#include "monty.h"

/**
 * load_file - Opens a specified file for reading.
 * @filename: The name of the file to open.
 */
void load_file(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (!filename || !file)
        log_error(2, filename);

    parse_file(file);
    fclose(file);
}

/**
 * parse_file - Reads and processes the contents of a file.
 * @file: Pointer to the file descriptor.
 */
void parse_file(FILE *file)
{
    int line_number;
    char *buffer = NULL;
    size_t length = 0;

    for (line_number = 1; getline(&buffer, &length, file) != -1; line_number++)
        tokenize_and_execute(buffer, line_number);
    
    free(buffer);
}

/**
 * tokenize_and_execute - Breaks down each line into tokens and executes commands.
 * @buffer: The line read from the file.
 * @line_number: The current line number.
 */
int tokenize_and_execute(char *buffer, int line_number)
{
    char *opcode, *argument;
    const char *delimiter = "\n ";

    if (!buffer)
        log_error(4);

    opcode = strtok(buffer, delimiter);
    argument = strtok(NULL, delimiter);

    if (strcmp(opcode, "stack") == 0)
        return 0;
    if (strcmp(opcode, "queue") == 0)
        return 1;

    locate_and_execute(opcode, argument, line_number);
    return 0;
}

/**
 * locate_and_execute - Finds the appropriate function for a given opcode.
 * @opcode: The operation code.
 * @argument: The argument for the opcode.
 * @line_number: The line number for error reporting.
 */
void locate_and_execute(char *opcode, char *argument, int line_number)
{
    instruction_t commands[] = {
        {"push", push_to_stack},
        {"pall", display_stack},
        {"pint", show_top},
        {"pop", remove_top},
        {"nop", do_nothing},
        {"swap", swap_top_nodes},
        {"add", sum_nodes},
        {"sub", subtract_nodes},
        {"div", divide_nodes},
        {"mul", multiply_nodes},
        {"mod", modulate_nodes},
        {"pchar", display_char},
        {"pstr", display_string},
        {"rotl", rotate_left},
        {"rotr", rotate_right},
        {NULL, NULL}
    };

    if (opcode[0] == '#')
        return;

    for (int i = 0; commands[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, commands[i].opcode) == 0)
        {
            execute_command(commands[i].f, opcode, argument, line_number);
            return;
        }
    }
    log_error(3, line_number, opcode);
}

/**
 * execute_command - Executes the designated function based on opcode.
 * @func: Pointer to the function to be executed.
 * @opcode: The operation code string.
 * @argument: The argument string.
 * @line_number: The line number of the command.
 */
void execute_command(op_func func, char *opcode, char *argument, int line_number)
{
    stack_t *new_node;
    int multiplier = 1;

    if (strcmp(opcode, "push") == 0)
    {
        if (argument && argument[0] == '-')
        {
            argument++;
            multiplier = -1;
        }
        if (!argument)
            log_error(5, line_number);

        for (int i = 0; argument[i] != '\0'; i++)
        {
            if (!isdigit(argument[i]))
                log_error(5, line_number);
        }
        new_node = create_node(atoi(argument) * multiplier);
        func(multiplier == 1 ? &new_node : &head, line_number);
    }
    else
    {
        func(&head, line_number);
    }
}
