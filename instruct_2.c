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
 * rotl - rotates the top element to bottom
 * then moves second top element to top
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotl(stack_t **stack, unsigned int nline)
{
stack_t *temp;
int top, second_top;
(void)nline;

if (stack == NULL || *stack == NULL)
{
nop(stack, nline);
}

top = (*stack)->n;
temp = *stack;

while (temp)
{
if (temp->next == NULL)
break;
temp = temp->next;
}

second_top = temp->n;
(*stack)->n = second_top;
temp->n = top;
}

/**
 * rotlop - rotates stack to left
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotlop(stack_t **stack, unsigned int nline)
{
stack_t *last, *tmp;

(void)nline;
if (!stack || !(*stack) || !((*stack)->next))
return;

tmp = *stack;
last = tmp;

while (last->next)
{
last = last->next;
}

last->next = tmp;
tmp->prev = last;
tmp->next->prev = NULL;
*stack = tmp->next;
tmp->next = NULL;
}

/**
 * rotrop - rotates stack to right
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotrop(stack_t **stack, unsigned int nline)
{
stack_t *last, *tmp;

(void)nline;
if (!stack || !(*stack) || !((*stack)->next))
return;

tmp = *stack;
last = tmp;

while (last->next)
{
last = last->next;
}

last->prev->next = NULL;
last->prev = NULL;
tmp->prev = last;
last->next = tmp;
*stack = last;
}
