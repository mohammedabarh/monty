#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_element_s - doubly linked list representation of a stack (or queue)
 * @value: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_element_s
{
    int value;
    struct stack_element_s *prev;
    struct stack_element_s *next;
} stack_element_t;

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
    void (*f)(stack_element_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void push_element(stack_element_t **stack, unsigned int line_number);
void print_all(stack_element_t **stack, unsigned int line_number);
void print_top_element(stack_element_t **stack, unsigned int line_number);
void pop_element(stack_element_t **stack, unsigned int line_number);
void swap_top_two(stack_element_t **stack, unsigned int line_number);
void add_top_two(stack_element_t **stack, unsigned int line_number);
void subtract_top_two(stack_element_t **stack, unsigned int line_number);
void divide_top_two(stack_element_t **stack, unsigned int line_number);
void multiply_top_two(stack_element_t **stack, unsigned int line_number);
void modulo_top_two(stack_element_t **stack, unsigned int line_number);
void rotate_left(stack_element_t **stack, unsigned int line_number);
void rotate_right(stack_element_t **stack, unsigned int line_number);
void print_char_top(stack_element_t **stack, unsigned int line_number);
void print_string(stack_element_t **stack, unsigned int line_number);

void handle_error(int error_code, unsigned int line_number, char *op);
void file_error(char *filename);
void usage_error(void);

void process_file(char *filename);
char **tokenize_line(char *line);
void execute_instruction(char *line, stack_element_t **stack, unsigned int line_number);
void free_stack(stack_element_t *stack);

extern stack_element_t *top;

#endif /* MONTY_H */
