#include "monty.h"

/**
 * _rotl - Rotl
 *
 * @h: Stack
*/
void _rotl(stack_t **h)
{
	stack_t *q, *w;

	q = *h;
	*h = (*h)->next;
	(*h)->prev = NULL;
	q->next = NULL;
	w = *h;
	while (w->next != NULL)
		w = w->next;
	w->next = q;
	q->prev = w;
}
