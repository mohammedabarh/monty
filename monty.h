#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

/* Data structure for stack nodes */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Function pointer type for opcode functions */
typedef void (*op_func)(stack_t **, unsigned int);

/* Structure to map opcodes to functions */
typedef struct instruction_s
{
    char *opcode;
    op_func f;
} instruction_t;

/* Global variable for the top of the stack */
extern stack_t *head;  // Declaration of the external head variable

/* Error handling functions */
void log_error(int code, ...);
void handle_specific_errors(int code, ...);
void handle_string_errors(int code, ...);

/* File handling functions */
void load_file(char *filename);
void parse_file(FILE *file);
int tokenize_and_execute(char *buffer, int line_number);
void locate_and_execute(char *opcode, char *argument, int line_number);
void execute_command(op_func func, char *opcode, char *argument, int line_number);

/* Stack manipulation functions */
stack_t *create_node(int value);
void clear_stack(void);
void push_to_stack(stack_t **new_node, unsigned int line_number);
void display_stack(stack_t **stack, unsigned int line_number);
void remove_top(stack_t **stack, unsigned int line_number);
void show_top(stack_t **stack, unsigned int line_number);
void enqueue(stack_t **new_node, unsigned int line_number);

/* Arithmetic functions */
void swap_top_nodes(stack_t **stack, unsigned int line_number);
void sum_nodes(stack_t **stack, unsigned int line_number);
void subtract_nodes(stack_t **stack, unsigned int line_number);
void divide_nodes(stack_t **stack, unsigned int line_number);
void multiply_nodes(stack_t **stack, unsigned int line_number);
void modulate_nodes(stack_t **stack, unsigned int line_number);

/* String manipulation functions */
void display_char(stack_t **stack, unsigned int line_number);
void display_string(stack_t **stack, unsigned int line_number);
void rotate_left(stack_t **stack, unsigned int line_number);
void rotate_right(stack_t **stack, unsigned int line_number);

/* Miscellaneous functions */
void do_nothing(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
