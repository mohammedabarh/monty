#include "monty.h"

/**
 * log_error - Logs various error messages based on error codes.
 * @code: The error code indicating the type of error.
 */
void log_error(int code, ...)
{
    va_list args;
    char *operation;
    int line_number;

    va_start(args, code);
    switch (code)
    {
        case 1:
            fprintf(stderr, "USAGE: monty file\n");
            break;
        case 2:
            fprintf(stderr, "Error: Unable to open file %s\n", va_arg(args, char *));
            break;
        case 3:
            line_number = va_arg(args, int);
            operation = va_arg(args, char *);
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, operation);
            break;
        case 4:
            fprintf(stderr, "Error: Memory allocation failed\n");
            break;
        case 5:
            fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
            break;
        default:
            break;
    }
    clear_stack();
    exit(EXIT_FAILURE);
}

/**
 * handle_specific_errors - Manages specific error cases.
 * @code: Error codes for specific conditions.
 */
void handle_specific_errors(int code, ...)
{
    va_list args;
    char *operation;
    int line_number;

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
            line_number = va_arg(args, unsigned int);
            operation = va_arg(args, char *);
            fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, operation);
            break;
        case 9:
            fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
            break;
        default:
            break;
    }
    clear_stack();
    exit(EXIT_FAILURE);
}

/**
 * handle_string_errors - Manages errors related to strings.
 * @code: Error codes for string conditions.
 */
void handle_string_errors(int code, ...)
{
    va_list args;
    int line_number;

    va_start(args, code);
    line_number = va_arg(args, int);
    switch (code)
    {
        case 10:
            fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
            break;
        case 11:
            fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
            break;
        default:
            break;
    }
    clear_stack();
    exit(EXIT_FAILURE);
}
