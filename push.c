#include "monty.h"

/**
 * _push - Push
 *
 * @Buf: Buffer
 * @h: Stack
*/
void _push(char **Buf, stack_t **h, int l, char **buff, int t)
{
	int n, i = 0;
	stack_t *new, *q;

	if (!Buf[1])
	{
		while (i <= t)
        	{
        	        free(buff[i]);
        	        i++;
        	}
        	free(buff);
        	while (*h)
        	{
                	q = *h;
                	*h = (*h)->next;
                	free(q);
        	}
		free(Buf[0]);
		if (Buf[1])
			free(Buf[1]);
		fprintf(stderr, "L%d: usage: push integer\n", l + 1);
		exit(EXIT_FAILURE);
	}
	n = atoi(Buf[1]);
	if (n != 0)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			while (i <= t)
                	{
                	        free(buff[i]);
                	        i++;
                	}
                	free(buff);
                	while (*h)
                	{
                	        q = *h;
                	        *h = (*h)->next;
                	        free(q);
                	}
			free(Buf[0]);
			if (Buf[1])
				free(Buf[1]);
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
		while (i <= t)
                {
                        free(buff[i]);
                        i++;
                }
                free(buff);
                while (*h)
                {
                        q = *h;
                        *h = (*h)->next;
                        free(q);
                }
		free(Buf[0]);
		if (Buf[1])
			free(Buf[1]);
		fprintf(stderr, "L%d: usage: push integer\n", l + 1);
		exit(EXIT_FAILURE);
	}
}
