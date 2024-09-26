#include "monty.h"

/**
 * log_error - Outputs specific error messages based on the error code.
 * @code: The error codes are as follows:
 * (1) => Missing or too many files.
 * (2) => Cannot open or read the specified file.
 * (3) => Invalid instruction in the file.
 * (4) => Memory allocation failure.
 * (5) => Non-integer argument for "push".
 * (6) => Empty stack for pint operation.
 * (7) => Empty stack for pop operation.
 * (8) => Stack too short for the operation.
 */
void log_error(int code, ...)
{
	va_list args;
	char *instruction;
	int line_num;

	va_start(args, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			line_num = va_arg(args, int);
			instruction = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, instruction);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * handle_additional_errors - Processes specific error scenarios.
 * @code: The error codes are as follows:
 * (6) => Empty stack for pint operation.
 * (7) => Empty stack for pop operation.
 * (8) => Stack too short for the operation.
 * (9) => Division by zero error.
 */
void handle_additional_errors(int code, ...)
{
	va_list args;
	char *instruction;
	int line_num;

	va_start(args, code);
	switch (code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
			line_num = va_arg(args, unsigned int);
			instruction = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, instruction);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * handle_string_errors - Manages string-related errors.
 * @code: The error codes are as follows:
 * (10) ~> Value outside ASCII bounds.
 * (11) ~> Stack is empty.
 */
void handle_string_errors(int code, ...)
{
	va_list args;
	int line_num;

	va_start(args, code);
	line_num = va_arg(args, int);
	switch (code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
