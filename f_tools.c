#include "monty.h"

/**
 * open_file_handler - Opens a file.
 * @file_name: The file name/path.
 * 
 * Return: void
 */
void open_file_handler(char *file_name)
{
    FILE *file_descriptor = fopen(file_name, "r");

    if (file_name == NULL || file_descriptor == NULL)
        handle_error(2, file_name);

    read_input_file(file_descriptor);
    fclose(file_descriptor);
}

/**
 * read_input_file - Reads a file.
 * @file_descriptor: Pointer to file descriptor.
 * 
 * Return: void
 */
void read_input_file(FILE *file_descriptor)
{
    int line_number;
    int format = 0;
    char *buffer = NULL;
    size_t len = 0;

    for (line_number = 1; getline(&buffer, &len, file_descriptor) != -1; line_number++)
    {
        format = parse_line_content(buffer, line_number, format);
    }
    free(buffer);
}

/**
 * parse_line_content - Separates each line into tokens to determine
 * which function to call.
 * @buffer: Line from the file.
 * @line_number: Line number.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 * If 1, nodes will be entered as a queue.
 * 
 * Return: Returns 0 if the opcode is stack, 1 if queue.
 */
int parse_line_content(char *buffer, int line_number, int format)
{
    char *opcode, *value;
    const char *delimiter = "\n ";

    if (buffer == NULL)
        handle_error(4);

    opcode = strtok(buffer, delimiter);
    if (opcode == NULL)
        return (format);
    
    value = strtok(NULL, delimiter);

    if (strcmp(opcode, "stack") == 0)
        return (0);
    if (strcmp(opcode, "queue") == 0)
        return (1);

    locate_function(opcode, value, line_number, format);
    return (format);
}

/**
 * locate_function - Finds the appropriate function for the opcode.
 * @opcode: Opcode.
 * @value: Argument of opcode.
 * @line_number: Line number.
 * @format: Storage format. If 0 nodes will be entered as a stack,
 * if 1 nodes will be entered as a queue.
 * 
 * Return: void
 */
void locate_function(char *opcode, char *value, int line_number, int format)
{
    int i;
    int flag = 1;

    instruction_t func_list[] = {
        {"push", push_to_stack},
        {"pall", display_stack},
        {"pint", display_top},
        {"pop", remove_top},
        {"nop", no_operation},
        {"swap", swap_stack_nodes},
        {"add", add_stack_nodes},
        {"sub", subtract_stack_nodes},
        {"div", divide_stack_nodes},
        {"mul", multiply_stack_nodes},
        {"mod", modulate_stack_nodes},
        {"pchar", display_char},
        {"pstr", display_string},
        {"rotl", rotate_left},
        {"rotr", rotate_right},
        {NULL, NULL}
    };

    if (opcode[0] == '#')
        return;

    for (i = 0; func_list[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, func_list[i].opcode) == 0)
        {
            execute_function(func_list[i].f, opcode, value, line_number, format);
            flag = 0;
        }
    }
    if (flag == 1)
        handle_error(3, line_number, opcode);
}

/**
 * execute_function - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @opcode: String representing the opcode.
 * @value: String representing a numeric value.
 * @line_number: Line number for the instruction.
 * @format: Format specifier. If 0, nodes will be entered as a stack,
 * if 1, nodes will be entered as a queue.
 * 
 * Return: void
 */
void execute_function(op_func func, char *opcode, char *value, int line_number, int format)
{
    stack_t *node;
    int flag = 1;
    int i;

    if (strcmp(opcode, "push") == 0)
    {
        if (value != NULL && value[0] == '-')
        {
            value = value + 1;
            flag = -1;
        }
        if (value == NULL)
            handle_error(5, line_number);
        
        for (i = 0; value[i] != '\0'; i++)
        {
            if (isdigit(value[i]) == 0)
                handle_error(5, line_number);
        }
        
        node = create_stack_node(atoi(value) * flag);
        if (format == 0)
            func(&node, line_number);
        if (format == 1)
            enqueue_to_queue(&node, line_number);
    }
    else
    {
        func(&head, line_number);
    }
}
