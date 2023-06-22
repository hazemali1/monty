#include "monty.h"

/**
 * _pop - Pop
 * @h: Stack
 * @buff: Buffer
 * @s: size of buffer
 * @l: line number
 * @Buf: Pointer
*/
void _pop(stack_t **h, char **buff, int s, int l, char **Buf)
{
	int i = 0;
	stack_t *q;

        if (*h == NULL)
        {
                while (i <= s)
                {
                    free(buff[i]);
                    i++;
                }
                free(buff);
                free(Buf[0]);
                free(Buf[1]);
                fprintf(stderr, "L%d: can't pop an empty stack\n", l + 1);
                exit(EXIT_FAILURE);
        }
	q = (*h)->next;
    	if (q)
    	    q->prev = NULL;
    	free(*h);
    	*h = q;

}
