#include "monty.h"

/**
 * main - opens monty file for processing
 * @argc: arguments count
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
FILE *f;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

f = fopen(argv[1], "r");
if (!f)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
processfile(f);
return (EXIT_SUCCESS);
}
