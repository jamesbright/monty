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

/**
 * swap - swaps the topmost 2 elements of a stack
 * @stack: pointer to the head node
 * @nline: line number
 * Return: void
 */

void swap(stack_t **stack, unsigned int nline)
{
int temp;

if (stack == NULL || *stack == NULL || !((*stack)->next))
{
fprintf(stderr, "L%d: can't swap, stack too short\n", nline);
exit(EXIT_FAILURE);
}
temp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}


/**
 * pchar - prints char at top of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pchar(stack_t **stack, unsigned int nline)
{
char c;
stack_t *temp;

if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", nline);
exit(EXIT_FAILURE);
}

temp = *stack;
while (temp)
{
if (temp->prev == NULL)
break;
temp = temp->prev;
}

c = temp->n;
if (_isalpha(temp->n) == 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", nline);
exit(EXIT_FAILURE);
}
printf("%c\n", c);
}

/**
 * pstr - prints a str from ascii starting from the top
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pstr(stack_t **stack, unsigned int nline __attribute__((unused)))
{
stack_t *tmp;

tmp = *stack;
while (tmp != NULL)
{
if (tmp->n <= 0 || tmp->n > 127)
break;
printf("%c", tmp->n);
tmp = tmp->next;
}
printf("\n");
}
