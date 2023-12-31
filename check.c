#include "monty.h"

/**
 * check - Check
 *
 * @buff: Buffer
*/
void check(char **buff, stack_t **h, int p)
{
	int s = 0, d, t = p, mode = 0;
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
			_push(Buf, h, s, buff, t, mode);
		}
		else if (strcmp(Buf[0], "pall") == 0 || strcmp(Buf[0], "pall\n") == 0)
			_pall(h);
		else if (strcmp(Buf[0], "pint") == 0 || strcmp(Buf[0], "pint\n") == 0)
		{
			if (d == 1)
				Buf[1] = NULL;
			_pint(h, buff, t, s, Buf);
		}
		else if (strcmp(Buf[0], "pop") == 0 || strcmp(Buf[0], "pop\n") == 0)
		{
			if (d == 1)
				Buf[1] = NULL;
			_pop(h, buff, t, s, Buf);
		}
		else if (strcmp(Buf[0], "swap") == 0 || strcmp(Buf[0], "swap\n") == 0)
		{
			if (d == 1)
                                Buf[1] = NULL;
			_swap(h, buff, t, s, Buf);
		}
		else if (strcmp(Buf[0], "add") == 0 || strcmp(Buf[0], "add\n") == 0)
                {
                        if (d == 1)
                                Buf[1] = NULL;
                        _add(h, buff, t, s, Buf);
                }
		else if (strcmp(Buf[0], "sub") == 0 || strcmp(Buf[0], "sub\n") == 0)
                {
                        if (d == 1)
                                Buf[1] = NULL;
                        _sub(h, buff, t, s, Buf);
                }
		else if (strcmp(Buf[0], "div") == 0 || strcmp(Buf[0], "div\n") == 0)
                {
                        if (d == 1)
                                Buf[1] = NULL;
                        _div(h, buff, t, s, Buf);
                }
		else if (strcmp(Buf[0], "mul") == 0 || strcmp(Buf[0], "mul\n") == 0)
                {
                        if (d == 1)
                                Buf[1] = NULL;
                        _mul(h, buff, t, s, Buf);
                }
		else if (strcmp(Buf[0], "mod") == 0 || strcmp(Buf[0], "mod\n") == 0)
                {
                        if (d == 1)
                                Buf[1] = NULL;
                        _mod(h, buff, t, s, Buf);
                }
		else if (strcmp(Buf[0], "pchar") == 0 || strcmp(Buf[0], "pchar\n") == 0)
                {
                        if (d == 1)
                                Buf[1] = NULL;
                        _pchar(h, buff, t, s, Buf);
                }
		else if (strcmp(Buf[0], "pstr") == 0 || strcmp(Buf[0], "pstr\n") == 0)
			_pstr(h);
		else if (strcmp(Buf[0], "rotl") == 0 || strcmp(Buf[0], "rotl\n") == 0)
			_rotl(h);
		else if (strcmp(Buf[0], "rotr") == 0 || strcmp(Buf[0], "rotr\n") == 0)
			_rotr(h);
		else if (strcmp(Buf[0], "stack") == 0 || strcmp(Buf[0], "stack\n") == 0)
			mode = 0;
		else if (strcmp(Buf[0], "queue") == 0 || strcmp(Buf[0], "queue\n") == 0)
			mode = 1;
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
