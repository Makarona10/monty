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

int perform_op(stack_t** stack, unsigned int lineNum, char* line)
{
	char* operation;
	size_t x;
	instruction_t operate[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", _pop},
		{"pint", pint}
	};

	operation = strtok(line, " \n\t\r");
	if (operation && operation[0] == '#')
		return (0);
	pub.n = strtok(NULL, " \n\t\r");
	/*printf("LINE: %d\n", lineNum);*/
	x = 0;
	while (operation && (x < 4))
	{
		/*printf("-%s-\n", operation);*/
		if (!strcmp(operate[x].opcode, operation))
		{
			/*printf("%s\n", operate[x].opcode);*/
			operate[x].f(stack, lineNum);
			return (0);
		}
		x++;
	}

	if (x == 4)
		fprintf(stderr, "L%u: unknown instruction %s\n", lineNum, operation);

	return (1);
}
