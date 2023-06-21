#include "monty.h"

/**
 * main - Main function
 *
 * @argc: Argc
 * @argv: Argv
 *
 * Return: Always 0
*/
int main(int argc, char *argv[])
{
	int s = 0, i;
	size_t size = 0;
	char *buff[1024] = {NULL};
	FILE *o;
	stack_t *h = NULL, *q;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	o = fopen(argv[1], "r");
	if (o == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&buff[s], &size, o)) != -1)
		s++;
	buff[s] = NULL;
	fclose(o);
	check(buff, &h);
	for (i = 0; i < s; i++)
		free(buff[i]);
	while (h)
	{
		q = h;
		h = h->next;
		free(q);
	}
	return (0);
}
