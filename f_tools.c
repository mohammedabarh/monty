#include "monty.h"

void more_err(unsigned int line_number, const char *message)
{
    fprintf(stderr, "L%d: %s\n", line_number, message);
    exit(EXIT_FAILURE);
}
