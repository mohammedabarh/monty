#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    open_script(argv[1]);
    free_stack();
    return (0);
}

/**
 * create_new_node - Allocates memory for a new node.
 * @n: Value to be stored in the node.
 * Return: Pointer to the new node or NULL on failure.
 */
stack_t *create_new_node(int n)
{
    stack_t *node = malloc(sizeof(stack_t));

    if (node == NULL)
        print_error(4);
    node->n = n;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

/**
 * free_stack - Frees the entire stack.
 */
void free_stack(void)
{
    stack_t *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

/**
 * append_to_queue - Appends a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: Line number of the operation (optional for logging).
 */
void append_to_queue(stack_t **new_node, unsigned int ln)
{
    stack_t *tmp;

    // Use the parameter for logging or error handling
    if (new_node == NULL || *new_node == NULL)
    {
        fprintf(stderr, "Error at line %u: new_node is NULL\n", ln);
        exit(EXIT_FAILURE);
    }

    if (head == NULL)
    {
        head = *new_node;
        return;
    }

    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *new_node;
    (*new_node)->prev = tmp;
}
