#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2)
        more_err(0, "USAGE: monty file");

    file = fopen(argv[1], "r");
    if (!file)
        more_err(0, "Error: Can't open file");

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \n\t");
        if (opcode && opcode[0] != '#')
        {
            // Handle opcode
            ...
        }
    }

    free(line);
    fclose(file);
    // Free stack
    return (EXIT_SUCCESS);
}
