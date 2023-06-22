#include "monty.h"

/**
 * _swap -Swapping
 * 
 * @h: Stack
 * @buff: Buffer
 * @s: size
 * @l:line
 * @Buf: Getline
*/
void _swap(stack_t **h, char **buff, int s, int l, char **Buf)
{
	stack_t *q;
	int i = 0;

	if (*h == NULL || (*h)->next == NULL)
	{
		while (i <= s)
                {
                    free(buff[i]);
                    i++;
                }
                free(buff);
                free(Buf[0]);
                free(Buf[1]);
                if (*h)
                        free(*h);
		fprintf(stderr, "L%d: can't swap,  stack too short\n", l + 1);
		exit(EXIT_FAILURE);
	}
	q = *h;
	*h = (*h)->next;
	(*h)->prev = NULL;
	if ((*h)->next)
		(*h)->next->prev = q;
	q->next = (*h)->next;
	(*h)->next = q;
	q->prev = *h;
}
