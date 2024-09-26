#include "monty.h"

/**
 * open_script - Opens the Monty script file.
 * @filename: Name of the script file to be opened.
 */
void open_script(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (filename == NULL || file == NULL)
		print_error(2, filename);

	read_script(file);
	fclose(file);
}

/**
 * read_script - Reads the Monty script line by line.
 * @file: File descriptor for the opened script.
 */
void read_script(FILE *file)
{
	int line_num = 1, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	while (getline(&buffer, &length, file) != -1)
	{
		format = process_line(buffer, line_num, format);
		line_num++;
	}
	free(buffer);
}

/**
 * process_line - Tokenizes and processes each line of the script.
 * @buffer: Line content from the script.
 * @line_num: Line number being processed.
 * @format: Determines whether stack or queue is used.
 * Return: Updated format (0 for stack, 1 for queue).
 */
int process_line(char *buffer, int line_num, int format)
{
	char *opcode, *arg;
	const char *delim = "\n ";

	if (buffer == NULL)
		print_error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);

	arg = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	execute_opcode(opcode, arg, line_num, format);
	return (format);
}

/**
 * execute_opcode - Executes the appropriate function based on the opcode.
 * @opcode: The operation code.
 * @arg: The argument provided with the opcode.
 * @line_num: The line number in the script.
 * @format: The format (0 = stack, 1 = queue).
 */
void execute_opcode(char *opcode, char *arg, int line_num, int format)
{
	int i, found = 0;

	instruction_t commands[] = {
		{"push", push_to_stack},
		{"pall", display_stack},
		{"pint", show_top},
		{"pop", remove_top},
		{"nop", do_nothing},
		{"swap", swap_top_nodes},
		{"add", add_top_nodes},
		{"sub", subtract_top_nodes},
		{"div", divide_top_nodes},
		{"mul", multiply_top_nodes},
		{"mod", modulo_top_nodes},
		{"pchar", print_char_node},
		{"pstr", print_string_nodes},
		{"rotl", rotate_left},
		{"rotr", rotate_right},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (i = 0; commands[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, commands[i].opcode) == 0)
		{
			execute_function(commands[i].f, opcode, arg, line_num, format);
			found = 1;
			break;
		}
	}

	if (found == 0)
		print_error(3, line_num, opcode);
}

/**
 * execute_function - Executes the specific opcode function.
 * @func: Function pointer to the operation.
 * @opcode: The operation code.
 * @arg: The argument for the operation.
 * @line_num: Line number of the operation in the script.
 * @format: Format to determine stack or queue.
 */
void execute_function(op_func func, char *opcode, char *arg, int line_num, int format)
{
	stack_t *new_node;
	int is_negative = 1, i;

	if (strcmp(opcode, "push") == 0)
	{
		if (arg != NULL && arg[0] == '-')
		{
			arg = arg + 1;
			is_negative = -1;
		}

		if (arg == NULL)
			print_error(5, line_num);

		for (i = 0; arg[i] != '\0'; i++)
		{
			if (!isdigit(arg[i]))
				print_error(5, line_num);
		}

		new_node = create_new_node(atoi(arg) * is_negative);
		if (format == 0)
			func(&new_node, line_num);
		else
			append_to_queue(&new_node, line_num);
	}
	else
	{
		func(&head, line_num);
	}
}

