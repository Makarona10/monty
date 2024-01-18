#include "monty.h"

/**
 * _push - pushes the element into ds
 *
 * @head: A pointer the head of ds
 *
 * @lineNum: The line number in monty file
 *
 * Return: void
*/

void _push(stack_t** head, unsigned int lineNum)
{
	int x, n;
	x = 0;
	if (pub.n)
	{
		if (pub.n[0] == '-')
			x = 1;
		for (; pub.n[x]; x++)
		{
			if (pub.n[x] < 48 || pub.n[x] > 57)
			{
				fprintf(stderr, "L%u: usage: push integer\n", lineNum);
				free(pub.line);
				fclose(pub.f);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", lineNum);
		free(pub.line);
		fclose(pub.f);
		exit(EXIT_FAILURE);
	}
	n = atoi(pub.n);
	if ((pub.flag) == 0)
	{
		toStack(head, n);
	}
	else
	{
	};
}
