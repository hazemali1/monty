#include "monty.h"

/**
 * check - Check
 *
 * @buff: Buffer
*/
void check(char **buff, stack_t **h, int p)
{
	int s = 0, d;
	char *str;
	char Buf[1024][1024];

	while (buff[s] && p > 0)
	{
		d = 0;
		str = strtok(buff[s], " ");
		while (str != NULL)
		{
			strcpy(Buf[d], str);
			str = strtok(NULL, " ");
			d++;
		}
		if (strcmp(Buf[0], "push") == 0 || strcmp(Buf[0], "push\n") == 0)
		{
			_push(Buf[1], h, s);
		}
		else if (strcmp(Buf[0], "pall") == 0 || strcmp(Buf[0], "pall\n") == 0)
			_pall(h);
		s++;
		p--;
	}
}
