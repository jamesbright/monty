#include "monty.h"

/**
 * add - adds top two elements of the stack
 * @stack: pointer to the head node of the stack
 * @nline: the line number
 * Return: void
 */

void add(stack_t **stack, unsigned int nline)
{

stack_t *tmp;

if (stack == NULL || *stack == NULL || !((*stack)->next))
{
fprintf(stderr, "L%d: can't add, stack too short", nline);
exit(EXIT_FAILURE);
}

tmp = *stack;
(*stack)->next->n = (*stack)->next->n + (*stack)->n;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(tmp);
}



/**
 * subop - subtracts the top two elements and stores it in second element
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void sub(stack_t **stack, unsigned int nline)
{
stack_t *temp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", nline);
exit(EXIT_FAILURE);
}

temp = *stack;
(*stack)->next->n -= (*stack)->n;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);
}

/**
 * divop - divides the top two elements and stores it in second element
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void divop(stack_t **stack, unsigned int nline)
{
stack_t *temp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't div, stack too short\n", nline);
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", nline);
exit(EXIT_FAILURE);
}

temp = *stack;
(*stack)->next->n /= (*stack)->n;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);
}

/**
 * mulop - multiplies the top two elements and stores it in second element
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void mul(stack_t **stack, unsigned int nline)
{
stack_t *temp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", nline);
exit(EXIT_FAILURE);
}

temp = *stack;
(*stack)->next->n *= (*stack)->n;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);
}

/**
 * modop - multiplies the top two elements and stores it in second element
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void mod(stack_t **stack, unsigned int nline)
{
stack_t *temp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", nline);
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", nline);
exit(EXIT_FAILURE);
}

temp = *stack;
(*stack)->next->n %= (*stack)->n;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);
}
