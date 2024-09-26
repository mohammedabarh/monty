#include "monty.h"

/**
 * handle_error - Handles various error conditions
 * @error_code: The error code
 * @line_number: Line number where the error occurred
 * @op: The operation that caused the error
 */
void handle_error(int error_code, unsigned int line_number, char *op)
{
    switch (error_code)
    {
        case 1:
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
            break;
        case 2:
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            break;
        case 3:
            fprintf(stderr, "Error: malloc failed\n");
            break;
        case 4:
            fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
            break;
        case 5:
            fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
            break;
        default:
            fprintf(stderr, "Unknown error occurred\n");
    }
    exit(EXIT_FAILURE);
}

/**
 * file_error - Prints file error message and exits
 * @filename: Name of the file that couldn't be opened
 */
void file_error(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    exit(EXIT_FAILURE);
}

/**
 * usage_error - Prints usage error message and exits
 */
void usage_error(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}
