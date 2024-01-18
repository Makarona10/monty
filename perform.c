#include "monty.h"

/**
 * perform_op - performs the monty file lines
 *
 * @stack: The stack that operation will be performed on
 *
 * @lineNum: The number of line the operation
 *
 * @line: The line contains the operation will be performed
 *
 * Return: 1 when succeeds, 0 when fails
*/

int perform_op(stack_t** ds, unsigned int lineNum, char* line, FILE *f)
{
	char* operation;
	size_t x;
	instruction_t operate[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", _pop},
		{"pint", pint}
	};

	operation = strtok(line, " \n\t");
	if (operation && operation[0] == '#')
		return (0);
	pub.n = strtok(NULL, " \n\t");
	x = 0;
	while (operation && (x < 4))
	{
		if (!strcmp(operate[x].opcode, operation))
		{
			operate[x].f(ds, lineNum);
			return (0);
		}
		x++;
	}

	if (operation && (x == 4))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, operation);
		fclose(f);
		free(line);
		freeDS(*ds);
		exit(EXIT_FAILURE);
	}
	return (1);
}
