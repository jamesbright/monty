#include "monty.h"

/**
 * processfile - reads and processes file one line at a time
 * @f: file to be processed
 *
 * Return: void
 */

void processfile(FILE *f)
{
size_t size = 0;
meta_t *meta = NULL;
line_t line;

meta = malloc(sizeof(meta_t));
if(!meta)
{
fprintf(stderr, "Error: malloc failed");
exit(EXIT_FAILURE);
}
line.number = 0;
line.content = NULL;

meta->file = f;
meta->stack = NULL;
meta->buf = NULL;

while (getline(&(meta->buf), &size, meta->file) != -1)
{
line.number++;
processline(&line, meta->buf);
if(line.content)
get_op_func(line, meta)(&(meta->stack), line.number);
}
free(meta->buf);
free_stack(&(meta->stack));
fclose(meta->file);
free(meta);
}


/**
 * processline - stores a line of text as a token
 * @line: struct of line contents and number
 * @buffer: string of text read from file
 *
 * Return: void
 */

void processline(line_t *line, char *buffer)
{
unsigned int i;
char *token = NULL;

line->content = malloc(sizeof(char *) * 3);
if (!line->content)
{
fprintf(stderr, "Error: malloc failed");
exit(EXIT_FAILURE);
}

token = strtok(buffer, " '\n'");
for (i = 0; token && i < 2; i++)
{
line->content[i] = token;
token = strtok(NULL, " \n");
}

line->content[i] = NULL;

}


