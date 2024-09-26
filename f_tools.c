#include "monty.h"

/**
 * load_file - Opens a file for reading.
 * @filename: The name of the file to open.
 * Return: void
 */
void load_file(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (filename == NULL || file == NULL)
		log_error(2, filename);

	read_file_content(file);
	fclose(file);
}

/**
 * read_file_content - Reads from the opened file.
 * @file: Pointer to the file descriptor.
 * Return: void
 */
void read_file_content(FILE *file)
{
	int line_num, mode = 0;
	char *line_buffer = NULL;
	size_t buffer_size = 0;

	for (line_num = 1; getline(&line_buffer, &buffer_size, file) != -1; line_num++)
	{
		mode = parse_line_content(line_buffer, line_num, mode);
	}
	free(line_buffer);
}

/**
 * parse_line_content - Tokenizes each line to determine the command.
 * @line_buffer: The current line from the file.
 * @line_num: The current line number.
 * @mode: Indicates stack (0) or queue (1).
 * Return: Returns 0 for stack, 1 for queue.
 */
int parse_line_content(char *line_buffer, int line_num, int mode)
{
	char *command, *arg;
	const char *delimiters = "\n ";

	if (line_buffer == NULL)
		log_error(4);

	command = strtok(line_buffer, delimiters);
	if (command == NULL)
		return (mode);
	arg = strtok(NULL, delimiters);

	if (strcmp(command, "stack") == 0)
		return (0);
	if (strcmp(command, "queue") == 0)
		return (1);

 locate_function(command, arg, line_num, mode);
	return (mode);
}

/**
 * locate_function - Finds and executes the appropriate function.
 * @command: The command to execute.
 * @arg: Associated argument for the command.
 * @line_num: The line number in the file.
 * @mode: Indicates stack or queue.
 * Return: void
 */
void locate_function(char *command, char *arg, int line_num, int mode)
{
	int i;
	int found = 1;

	instruction_t commands[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (command[0] == '#')
		return;

	for (found = 1, i = 0; commands[i].opcode != NULL; i++)
	{
		if (strcmp(command, commands[i].opcode) == 0)
		{
			invoke_function(commands[i].f, command, arg, line_num, mode);
			found = 0;
		}
	}
	if (found == 1)
		log_error(3, line_num, command);
}

/**
 * invoke_function - Calls the specified function.
 * @func: Pointer to the function to call.
 * @cmd: The command string.
 * @arg: The argument string.
 * @line_num: The line number for the command.
 * @mode: Indicates stack or queue.
 */
void invoke_function(op_func func, char *cmd, char *arg, int line_num, int mode)
{
	stack_t *node;
	int sign = 1;
	int i;

	if (strcmp(cmd, "push") == 0)
	{
		if (arg != NULL && arg[0] == '-')
		{
			arg++;
			sign = -1;
		}
		if (arg == NULL)
			log_error(5, line_num);
		for (i = 0; arg[i] != '\0'; i++)
		{
			if (!isdigit(arg[i]))
				log_error(5, line_num);
		}
		node = create_node(atoi(arg) * sign);
		if (mode == 0)
			func(&node, line_num);
		else
			add_to_queue(&node, line_num);
	}
	else
		func(&head, line_num);
}
