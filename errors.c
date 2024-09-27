#include "monty.h"

/* Error handling function */
void handle_error(const char *message, unsigned int line_number)
{
    fprintf(stderr, "L%u: %s\n", line_number, message);
    exit(EXIT_FAILURE);
}

