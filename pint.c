#include "monty.h"

void pint(stack_t** head, unsigned int lineNum)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNum);
		fclose(pub.f);
		free(pub.line);
		/*free_stack(*head);*/
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
