#include "monty.h"

/**
 * _push - Push
 *
 * @Buf: Buffer
 * @h: Stack
*/
void _push(char *Buf, stack_t **h, int l)
{
	int n;
	stack_t *new;

	if (Buf == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}
	n = atoi(Buf);
	if (n != 0)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new->n = n;
		if (*h == NULL)
		{
			new->next = NULL;
			new->prev = NULL;
			*h = new;
		}
		else
		{
			new->next = *h;
			new->prev = NULL;
			(*h)->prev = new;
			*h = new;
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}
}
