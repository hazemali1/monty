#include "monty.h"

/**
 * _rotr - Rotr
 *
 * @h: Stack
*/
void _rotr(stack_t **h)
{
	stack_t *q, *w, *a;

	q = *h;
	if (q && q->next)
	{
		w = *h;
		while (w->next)
			w = w->next;
		a = *h;
		while (a->next->next)
			a = a->next;
		a->next = NULL;
		w->prev = NULL;
		w->next = q;
		q->prev = w;
		*h = w;
	}
}
