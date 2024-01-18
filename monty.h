#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
*/

typedef struct stack_s
{
	int n;
	struct stack_s* prev;
	struct stack_s* next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char* opcode;
	void (*f)(stack_t** stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 * 
 * @arg: value
 * 
 * @file: pointer to monty file
 * 
 * @content: line content
 *
 * @flag: flag change stack <-> queue
 * 
 * Description: Holds the public vars needed
*/
typedef struct pub_s
{
	char *n;
	FILE *f;
	char *line;
	int flag;
}  pub_t;
extern pub_t pub;

instruction_t *op_array();
void toStack(stack_t* s_head, int n);
void _push(stack_t** head, unsigned int lineNum);
int perform_op(stack_t* stack, unsigned int lineNum, char* line);
void _pall(stack_t** head, unsigned int lineNum);
void _pop(stack_t** head, unsigned int lineNum);
void pint(stack_t** head, unsigned int lineNum);


#endif
