#include "monty.h"

/**
 * print_error - Handles various error messages based on error code.
 * @code: Error code corresponding to the specific error.
 */
void print_error(int code, ...)
{
	va_list args;
	char *op;
	int line_num;

	va_start(args, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			line_num = va_arg(args, int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
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
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * handle_stack_error - Handles stack-specific error messages.
 * @code: Error code relating to stack operations.
 */
void handle_stack_error(int code, ...)
{
	va_list args;
	int line_num;

	va_start(args, code);
	switch (code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			line_num = va_arg(args, unsigned int);
			fprintf(stderr, "L%d: operation failed, stack too short\n", line_num);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * char_stack_error - Handles errors related to char stack operations.
 * @code: Error code specific to character operations.
 */
void char_stack_error(int code, ...)
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
	free_stack();
	exit(EXIT_FAILURE);
}

