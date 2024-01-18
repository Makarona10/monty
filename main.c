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

pub_t pub = { NULL, NULL, NULL, 0 };

int main(int argc, char** argv)
{
	char* fline = NULL;
	FILE* f;
	size_t s = 0;
	int x;
	stack_t* ds = NULL;
	unsigned int line = 0;

	if (argc != 2)
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
	do
	{
		line++;
		fline = NULL;
		x = getline(&fline, &s, f);
		pub.line = fline;
		if (x > 0)
			perform_op(&ds, line, fline, f);
		free(fline);
	} while (x > 0);
	freeDS(ds);
	fclose(f);
	return (0);
}
