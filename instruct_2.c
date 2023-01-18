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
