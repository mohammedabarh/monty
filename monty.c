#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: List of arguments
 * 
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    open_file_handler(argv[1]);
    free_nodes();  // Ensure using free_nodes to free allocated memory
    return (0);
}

/**
 * create_stack_node - Creates a stack node.
 * @n: Number to go inside the node.
 * 
 * Return: Upon success, a pointer to the node. Otherwise NULL.
 */
stack_t *create_stack_node(int n)
{
    stack_t *node;

    node = malloc(sizeof(stack_t));
    if (node == NULL)
        handle_error(4);
    node->next = NULL;
    node->prev = NULL;
    node->n = n;
    return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
    stack_t *tmp;

    if (head == NULL)
        return;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

/**
 * enqueue_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @line_number: Line number of the opcode.
 */
void enqueue_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int line_number)
{
    stack_t *tmp;

    if (new_node == NULL || *new_node == NULL)
        exit(EXIT_FAILURE);

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
