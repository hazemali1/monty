#include "monty.h"

/**
 * _pint - Print top
 *
 * @h: Stack
*/
void _pint(stack_t **h, char **buff,int s, int l, char **Buf)
{
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
		fprintf(stderr, "L%d: can't pint, stack empty\n", l + 1);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*h)->n);
}
