#include "monty.h"

/**
 * add - adds top two elements of the stack
 * @stack: pointer to the head node of the stack
 * @nline: the line number
 * Return: void
 */

void add(stack_t **stack, unsigned int nline)
{


if (stack == NULL || *stack == NULL || !((*stack)->next))
{
fprintf(stderr, "L%d: can't add, stack too short", nline);
exit(EXIT_FAILURE);
}

(*stack)->next->n = (*stack)->next->n + (*stack)->n;
*stack = (*stack)->next;
(*stack)->prev = NULL;

}
