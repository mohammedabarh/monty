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
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/* File operations */
void open_script(char *filename);
int process_line(char *buffer, int line_num, int format);
void read_script(FILE *);
int len_chars(FILE *);
void execute_opcode(char *, char *, int, int);

/* Stack operations */
stack_t *create_new_node(int n);
void free_stack(void);
void display_stack(stack_t **, unsigned int);
void push_to_stack(stack_t **, unsigned int);
void append_to_queue(stack_t **, unsigned int);

void execute_function(op_func, char *, char *, int, int);

void show_top(stack_t **, unsigned int);
void remove_top(stack_t **, unsigned int);
void do_nothing(stack_t **, unsigned int);
void swap_top_nodes(stack_t **, unsigned int);

/* Math operations */
void add_top_nodes(stack_t **, unsigned int);
void subtract_top_nodes(stack_t **, unsigned int);
void divide_top_nodes(stack_t **, unsigned int);
void multiply_top_nodes(stack_t **, unsigned int);
void modulo_top_nodes(stack_t **, unsigned int);

/* String operations */
void print_char_node(stack_t **, unsigned int);
void print_string_nodes(stack_t **, unsigned int);
void rotate_left(stack_t **, unsigned int);

/* Error handling */
void print_error(int code, ...);
void handle_stack_error(int code, ...);
void char_stack_error(int code, ...);
void rotate_right(stack_t **, unsigned int);

#endif

