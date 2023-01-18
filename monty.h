#ifndef _MONTY_H_
#define _MONTY_H_
#define UNUSED(x) (void)(x)
#define  _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>


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

/**
 * struct line_t - contents of line and corresponding number
 * @contents: array of tokens read from the line
 * @number: the line number
 *
 * Description: contents of a line and corresponding number
 */
typedef struct line
{
	unsigned int number;
	char **content;
} line_t;

/**
 * struct meta_s - holds information aboit a file
 * @buf: file buffer
 * @stack: stack data structure
 * @file: file
 */
typedef struct meta_s
{
	char *buf;
	stack_t *stack;
	FILE *file;
} meta_t;


/**
 * struct arg_s - data storage for arguments
 * @arg: argument
 * @flag: argumrnt flag
 *
 */
typedef struct arg_s
{
	int arg;
	int flag;
} arg_t;

extern arg_t arg;


/* Process functions */
void processfile(FILE *file);
void processline(line_t *line, char *buffer);

/* functions to work with stacks */
void push(stack_t **stack, unsigned int nline);
void pall(stack_t **stack, unsigned int nline);
void free_stack(stack_t **stack);

/* some useful functions */
void (*get_op_func(line_t line, meta_t *meta))(stack_t **, unsigned int);
int _isalpha(int c);

void nop(stack_t **stack, unsigned int nline);
void qpush(stack_t **stack, unsigned int nline);


/* Verification functions */
bool comment_check(line_t line);
void push_check(line_t line, meta_t *meta, char *opcode);


/* Verification functions */
bool comment_check(line_t line);
void push_check(line_t line, meta_t *meta, char *opcode);

/* Stack manipulation functions */
void pint(stack_t **stack, unsigned int nline);
void pop(stack_t **stack, unsigned int nline);
void swap(stack_t **stack, unsigned int nline);
void rotl(stack_t **stack, unsigned int nline);
void rotlop(stack_t **stack, unsigned int nline);
void rotrop(stack_t **stack, unsigned int nline);
void pchar(stack_t **stack, unsigned int nline);
void pstr(stack_t **stack, unsigned int nline);
void addqu(stack_t **stack, unsigned int nline);
void addst(stack_t **stack, unsigned int nline);

/* Math functions */
void subop(stack_t **stack, unsigned int nline);
void addop(stack_t **stack, unsigned int nline);
void divop(stack_t **stack, unsigned int nline);
void mulop(stack_t **stack, unsigned int nline);
void modop(stack_t **stack, unsigned int nline);
#endif /* END _MONTY_H_ */
