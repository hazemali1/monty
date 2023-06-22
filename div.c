#include "monty.h"

/**
 * _div -Swapping
 * 
 * @h: Stack
 * @buff: Buffer
 * @s: size
 * @l:line
 * @Buf: Getline
*/
void _div(stack_t **h, char **buff, int s, int l, char **Buf)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", l + 1);
		exit(EXIT_FAILURE);
	}
	else if ((*h)->n == 0)
	{
		while (i <= s)
                {
                    free(buff[i]);
                    i++;
                }
                free(buff);
                free(Buf[0]);
                free(Buf[1]);
		while (*h)
        	{
        	        q = *h;
        	        *h = (*h)->next;
        	        free(q);
        	}
                fprintf(stderr, "L%d: division by zero\n", l + 1);
                exit(EXIT_FAILURE);
	}
	r = (*h)->next->n / (*h)->n;
	(*h)->next->n = r;
	q = *h;
	(*h) = (*h)->next;
	(*h)->prev = NULL;
	free(q);
}
