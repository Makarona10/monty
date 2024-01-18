#include "monty.h"
/**
 * sswap - swaps the top two elements of the stack
 * 
 * @S_head: stack's head
 * 
 * @lineNum: lines' number
 * 
 * Return: void
*/
void sswap(stack_t** S_head, unsigned int lineNum)
{
	stack_t* iter;
	int len = 0, tmp;

	iter = *S_head;
	while (iter)
	{
		iter = iter->next;
		len++;
	}
	if (len <= 1)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNum);
		fclose(pub.f);
		free(pub.line);
		freeDS(*S_head);
		exit(EXIT_FAILURE);
	}
	iter = *S_head;
	tmp = iter->n;
	iter->n = iter->next->n;
	iter->next->n = tmp;
}