#include "monty.h"

/**
 * pall - Display
 *
 * @h: Stack
*/
void _pall(stack_t **h)
{
	stack_t *dis;

	dis = *h;
	if (dis == NULL)
		return;
	while (dis)
	{
		fprintf(stdout, "%d\n", dis->n);
		dis = dis->next;
	}
}
