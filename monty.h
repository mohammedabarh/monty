#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer value stored in the node
 * @prev: pointer to the previous element in the stack (or queue)
 * @next: pointer to the next element in the stack (or queue)
 *
 * Description: Structure representing a node in a doubly linked list
 * for stack and queue implementations, supporting LIFO and FIFO operations.
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its associated function
 * @opcode: the operation code
 * @f: function pointer to handle the opcode
 *
 * Description: Structure mapping opcodes to their respective handling functions
 * for stack and queue operations.
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/* File operations */
void open_file_handler(char *file_name);
int parse_line_content(char *buffer, int line_number, int format);
void read_input_file(FILE *);
int count_chars(FILE *);
void locate_function(char *, char *, int, int);

/* Stack operations */
stack_t *create_stack_node(int n);
void free_nodes(void);
void display_stack(stack_t **, unsigned int);
void push_to_stack(stack_t **, unsigned int);
void enqueue_to_queue(stack_t **, unsigned int);

void execute_function(op_func, char *, char *, int, int);

void display_top(stack_t **, unsigned int);
void remove_top(stack_t **, unsigned int);
void no_operation(stack_t **, unsigned int);
void swap_stack_nodes(stack_t **, unsigned int);

/* Math operations with nodes */
void add_stack_nodes(stack_t **, unsigned int);
void subtract_stack_nodes(stack_t **, unsigned int);
void divide_stack_nodes(stack_t **, unsigned int);
void multiply_stack_nodes(stack_t **, unsigned int);
void modulate_stack_nodes(stack_t **, unsigned int);

/* String operations */
void display_char(stack_t **, unsigned int);
void display_string(stack_t **, unsigned int);
void rotate_left(stack_t **, unsigned int);

/* Error handling */
void handle_error(int error_code, ...);
void handle_more_error(int error_code, ...);
void handle_string_error(int error_code, ...);
void rotate_right(stack_t **, unsigned int);

#endif
