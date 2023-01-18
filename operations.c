#include "monty.h"
/**
 * pint - prints the value at the top of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pint(stack_t **stack, unsigned int nline)
{
stack_t *temp;

if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", nline);
exit(EXIT_FAILURE);
}

temp = *stack;
while (temp)
{
if (temp->prev == NULL)
break;
temp = temp->prev;
}

printf("%d\n", temp->n);
}

/**
 * pop - removes the top element of stack
 * @stack: pointer to the top of stack
 * @nline: line number
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int nline)
{
if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", nline);
exit(EXIT_FAILURE);
}

if ((*stack)->next != NULL)
{
*stack = (*stack)->next;
free((*stack)->prev);
(*stack)->prev = NULL;
}
else
{
free(*stack);
*stack = NULL;
}
}
