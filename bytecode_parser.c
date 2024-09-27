#include "monty.h"

instruction_t opcodes[] = {
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {NULL, NULL}
};

/* Execute the bytecode */
void execute_bytecode(FILE *file)
{
    char line[1024];  /* Buffer to hold each line of input */
    unsigned int line_number = 0;
    stack_t *stack = NULL;  /* Stack initialization */
    char *opcode;           /* Moved declaration to the start */
    
    while (fgets(line, sizeof(line), file) != NULL)  /* Use fgets instead of getline */
    {
        line_number++;
        opcode = strtok(line, " \t\n");  /* Tokenize the line */
        if (!opcode || opcode[0] == '#')      /* Skip comments and empty lines */
            continue;

        if (strcmp(opcode, "push") == 0)  /* Special handling for 'push' */
        {
            char *arg = strtok(NULL, " \t\n");  /* Argument for push */
            if (!arg || (atoi(arg) == 0 && strcmp(arg, "0") != 0))
            {
                handle_error("usage: push integer", line_number);
            }
            push(&stack, line_number, atoi(arg));  /* Call push with the argument */
        }
        else
        {
            int i = 0;  /* Declare variable at start of the block */
            while (opcodes[i].opcode != NULL)
            {
                if (strcmp(opcode, opcodes[i].opcode) == 0)
                {
                    opcodes[i].f(&stack, line_number);
                    break;
                }
                i++;
            }
            if (opcodes[i].opcode == NULL)
                handle_error("unknown instruction", line_number);
        }
    }

    free_stack(stack);  /* Free the stack after parsing */
}

