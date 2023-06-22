#include "monty.h"

/**
 * _pchar - Swapping
 * 
 * @h: Stack
 * @buff: Buffer
 * @s: size
 * @l:line
 * @Buf: Getline
*/
void _pchar(stack_t **h, char **buff, int s, int l, char **Buf)
{
	stack_t *q;
	int i = 0;

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
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l + 1);
		exit(EXIT_FAILURE);
	}
	else if ((*h)->n < 0 || (*h)->n > 127)
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
                fprintf(stderr, "L%d: can't pchar, value out of range\n", l + 1);
                exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*h)->n);
}
