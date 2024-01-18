#include "monty.h"
/**
 * S_pop - Pops the stack's top element
 * 
 * @s_head: stack's head
 * 
 * @lineNum: line number
 * 
 * Return: void
*/
void S_pop(stack_t** s_head, unsigned int lineNum)
{
	stack_t* iter;

	if (*s_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNum);
		fclose(pub.f);
		free(pub.line);
		freeDS(*s_head);
		exit(EXIT_FAILURE);
	}
	iter = *s_head;
	*s_head = iter->next;
	free(iter);
}