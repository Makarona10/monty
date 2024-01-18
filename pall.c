#include "monty.h"

void _pall(stack_t **head, unsigned int lineNum)
{
	stack_t *h;
	(void)lineNum;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
