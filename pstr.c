#include "monty.h"

/**
 * _pstr - Print Str
 *
 * @h: Stack
*/
void _pstr(stack_t **h)
{
	stack_t *q;

	q = *h;
	while (q != NULL && q->n != 0 && q->n > 0 && q->n < 128)
	{
		fprintf(stdout, "%c", q->n);
		q = q->next;
	}
	fprintf(stdout, "\n");
}
