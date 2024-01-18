#include "monty.h"

/**
 * op_array - stores the functions and its keys
 *
 * Return: array of objects ("function name", "its key")
*/

instruction_t *op_array()
{
	instruction_t *ret;

	instruction_t arr[] = {
        {"push", _push},
        {"pall", _pall},
        {"pop", _pop},
        {"pint", pint}
	};
	ret = arr;
	return (ret);
}
