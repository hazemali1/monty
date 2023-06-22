#include "monty.h"

/**
 * _sub -Swapping
 * 
 * @h: Stack
 * @buff: Buffer
 * @s: size
 * @l:line
 * @Buf: Getline
*/
void _sub(stack_t **h, char **buff, int s, int l, char **Buf)
{
	stack_t *q;
	int i = 0, r;

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
		fprintf(stderr, "L%d: can't add, stack too short\n", l + 1);
		exit(EXIT_FAILURE);
	}
	r = (*h)->next->n - (*h)->n;
	(*h)->next->n = r;
	q = *h;
	(*h) = (*h)->next;
	(*h)->prev = NULL;
	free(q);
}
