#include "monty.h"

/**
 * _push - Push
 *
 * @Buf: Buffer
 * @h: Stack
*/
void _push(char **Buf, stack_t **h, int l, char **buff, int t, int mode)
{
	int n, i = 0;
	stack_t *new, *q, *k;

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
	if (n != 0 || (strlen(Buf[1]) == 2 && isdigit(Buf[1][0])))
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
		if (mode == 0)
		{
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
		else if (mode == 1)
		{
			if (*h == NULL)
			{
				new->next = NULL;
				new->prev = NULL;
				*h = new;
			}
			else
			{
				k = *h;
				while (k->next)
					k = k->next;
				new->next = NULL;
				new->prev = k;
				k->next = new;
			}

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
