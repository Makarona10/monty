#include "monty.h"
/**
 * adds - adds the top two elements of the stack.
 * 
 * @S_head: stacks' head
 * 
 * @lineNum: line number
 * 
 * Return: void
*/
void adds(stack_t** S_head, unsigned int lineNum)
{
	int len = 0, tmp;
	stack_t* iter;

	iter = *S_head;
	while (iter)
	{
		iter = iter->next;
		len++;
	}
	if (len <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNum);
		free(pub.line);
		fclose(pub.f);
		freeDS(*S_head);
		exit(EXIT_FAILURE);
	}
	iter = (*S_head);
	tmp = iter->n + iter->next->n;
	iter->next->n = tmp;
	(*S_head) = iter->next;
	free(iter);
}