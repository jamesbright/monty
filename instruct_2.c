#include "monty.h"
/**
 * qpush - pushes for queue instead of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void qpush(stack_t **stack, unsigned int nline)
{
stack_t *last_data, *new_data;

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

last_data = NULL;
if (*stack)
{
last_data = *stack;
while (last_data->next)
last_data = last_data->next;
last_data->next = new_data;
	}
else
new_data->prev = last_data;
new_data->next = NULL;
new_data->n = arg.arg;
*stack = new_data;
}

/**
 * rotl - rotate the stack to the top
 * @stack: stack
 * @nline: line number in monty file
 * Return: void
 */
void rotl(stack_t **stack, unsigned int nline __attribute__((unused)))
{
int tmp;
stack_t *ptr = *stack;

if (*stack == NULL)
return;
tmp = (*stack)->n;
while (ptr->next != NULL)
{
ptr->n = ptr->next->n;
ptr = ptr->next;
}
ptr->n = tmp;
}
/**
 * rotr - rotate the stack to the top
 * @stack: stack
 * @nline: line number in monty file
 * Return: void
 */
void rotr(stack_t **stack, unsigned int nline __attribute__((unused)))
{
int tmp;
stack_t *ptr = *stack;

if (*stack == NULL)
return;

while (ptr->next != NULL)
ptr = ptr->next;
tmp = ptr->n;
while (ptr->prev != NULL)
{
ptr->n = ptr->prev->n;
ptr = ptr->prev;
}
ptr->n = tmp;
}
