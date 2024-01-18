#include "monty.h"

/**
 * freeDS - frees ds
 * 
 * @dsHead: stack's head
 * 
 * Return: void
*/
void freeDS(stack_t* dsHead)
{
	stack_t* iter;

	iter = dsHead;
	while (dsHead)
	{
		iter = dsHead->next;
		free(dsHead);
		dsHead = iter;
	}
}