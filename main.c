#include "monty.h"
stack_t *head = NULL;

/**
 * main - Program entry point.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	load_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Allocates and initializes a new node.
 * @value: The integer value for the node.
 * Return: Pointer to the newly created node, or NULL on failure.
 */
stack_t *create_node(int value)
{
	stack_t *node = malloc(sizeof(stack_t));
	if (!node)
		log_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = value;
	return (node);
}

/**
 * free_nodes - Frees all nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * add_to_queue - Enqueues a new node at the end of the queue.
 * @new_node: Pointer to the new node to enqueue.
 * @line_num: The line number associated with the command.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int line_num)
{
	stack_t *current;

	if (!new_node || !*new_node)
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *new_node;
		return;
	}
	current = head;
	while (current->next)
		current = current->next;

	current->next = *new_node;
	(*new_node)->prev = current;
}
