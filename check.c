#include "monty.h"

/**
 * check - Check
 *
 * @buff: Buffer
*/
void check(char **buff, stack_t **h, int p)
{
	int s = 0, d, t = p;
	char *str;
	char *Buf[1024];

	while (buff[s] && p > 0)
	{
		d = 0;
		str = strtok(buff[s], " ");
		while (str != NULL)
		{
			Buf[d] = malloc(1024);
			if (Buf[d] == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			strcpy(Buf[d], str);
			str = strtok(NULL, " ");
			d++;
		}
		if (strcmp(Buf[0], "push") == 0 || strcmp(Buf[0], "push\n") == 0)
		{
			_push(Buf, h, s, buff, t);
		}
		else if (strcmp(Buf[0], "pall") == 0 || strcmp(Buf[0], "pall\n") == 0)
			_pall(h);
		else if (strcmp(Buf[0], "pint") == 0 || strcmp(Buf[0], "pint\n") == 0)
			_pint(h, buff, t, s, Buf);
		s++;
		p--;
		while (d > -1)
		{
			free(Buf[d - 1]);
			d--;
		}
		Buf[1] = NULL;
	}
}
