#include <stdio.h>
#include <stdlib.h>

#define TAPE_SIZE 30000

void brainfuck_interpreter(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char tape[TAPE_SIZE] = {0};
    char *ptr = tape;
    char command;
    while ((command = fgetc(file)) != EOF)
    {
        switch (command)
        {
            case '>': ptr++; break;
            case '<': ptr--; break;
            case '+': (*ptr)++; break;
            case '-': (*ptr)--; break;
            case '.': putchar(*ptr); break;
            case ',': *ptr = getchar(); break;
            case '[': // Implement loops as needed
                break;
            case ']': // Implement loops as needed
                break;
        }
    }
    fclose(file);
}
