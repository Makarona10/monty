#include "monty.h"

/**
 * toStack - pushes an element into stack
 *
 * @stack: The stack that the element will be pushed into
 *
 * @n: The element will be pushed
 *
 * Return: void
*/

void toStack(stack_t **s_head, int n)
{
	stack_t *nnode = malloc(sizeof(stack_t));

	if (!nnode)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	nnode->n = n;
	nnode->next = NULL;
	nnode->prev = NULL;
	if (*s_head)
		(*s_head)->prev = nnode;

	nnode->next = (*s_head);
	(*s_head) = nnode;
}
