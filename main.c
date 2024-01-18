#include "monty.h"

/**
 * main - a program to operate stack and queues operations with monty bytecode
 *
 * @argc: number of the program arguments.
 *
 * @argv: The monty file location.
 *
 * Return: if success 0, else it exits with the error number.
*/

pub_t pub = {NULL, NULL, NULL, 0};

int main (int argc, char **argv)
{
	FILE *f;
	unsigned int line = 0;
	size_t s = 0;
	char *fline = NULL;
	stack_t *stack = NULL;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	pub.f = f;
	while (getline(&fline, &s, f))
	{
		line++;
		if (fline)
			if (perform_op(stack, line, fline))
			{
				free(fline);
				fclose(f);
				exit(EXIT_FAILURE);
			}
		free(fline);
	}
	fclose(f);
	return (0);
}
