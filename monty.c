#include "monty.h"

stack_element_t *top = NULL;

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        usage_error();
    }

    process_file(argv[1]);

    return EXIT_SUCCESS;
}
