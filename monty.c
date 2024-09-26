#include "monty.h"

stack_t *head = NULL;  // Definition of the head variable

/**
 * main - Entry point of the Monty interpreter.
 * @argc: The count of command line arguments.
 * @argv: The command line arguments.
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    
    load_file(argv[1]);  // Load and process the file
    clear_stack();        // Clear the stack at the end
    return 0;
}

/**
 * create_node - Allocates memory for a new stack node.
 * @value: The integer to store in the node.
 * Return: A pointer to the newly created node or NULL on failure.
 */
stack_t *create_node(int value)
{
    stack_t *node = malloc(sizeof(stack_t));
    if (!node)
        log_error(4);  // Handle memory allocation error

    node->next = NULL;
    node->prev = NULL;
    node->n = value;
    return node;
}

/**
 * clear_stack - Frees all nodes in the stack.
 */
void clear_stack(void)
{
    stack_t *temp;

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * enqueue - Adds a new node to the end of the stack (queue mode).
 * @new_node: Pointer to the new node.
 * @line_number: The line number of the opcode.
 */
void enqueue(stack_t **new_node, unsigned int line_number)
{
    (void)line_number;  // Suppress unused parameter warning
    stack_t *temp;

    if (!new_node || !*new_node)
        exit(EXIT_FAILURE);
    if (!head)
    {
        head = *new_node;
        return;
    }
    temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = *new_node;
    (*new_node)->prev = temp;
}
