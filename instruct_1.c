#include "monty.h"

/**
 * push - pushes a node to the top of the stack
 * @stack: points to the top of stack
 * @nline: the line number
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int nline)
{
stack_t *new_data;

if (stack == NULL)
{
fprintf(stderr, "L%d: stack not found\n", nline);
exit(EXIT_FAILURE);
}

new_data = malloc(sizeof(stack_t));
if (new_data == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
free_stack(stack);
exit(EXIT_FAILURE);
}

new_data->next = *stack;
new_data->prev = NULL;
new_data->n = arg.arg;

if (*stack)
(*stack)->prev = new_data;

*stack = new_data;
}


/**
 * pall - prints all data in stack
 * @stack: pointer to the head of stack
 * @nline: line number
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int nline)
{
stack_t *temp;
(void)nline;

temp = *stack;
while (temp)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}


/**
 * free_stack - frees all nodes in a stack
 * @stack: pointer to the head node pointer of stack
 *
 * Return: Nothing.
 */
void free_stack(stack_t **stack)
{
stack_t *temp = NULL;

if (stack == NULL || *stack == NULL)
return;

while (*stack != NULL)
{
temp = (*stack)->next;
free(*stack);
*stack = temp;
}
}



/**
 * nop - does literally nothing
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int nline)
{
(void)stack;
(void)nline;
}

/**
 * _isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
return (1);
else
return (0);
}
