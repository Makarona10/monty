#include "monty.h"

void _pall(stack_t **head, unsigned int lineNum)
{
	(void)lineNum;
	stack_t *s_h;

	s_h = *head;
	if (s_h == NULL)
		return;
	puts("PALLL");
	while (s_h)
	{
		printf("%d\n", s_h->n);
		s_h = s_h->next;
	}
}
