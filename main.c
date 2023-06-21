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
	int s = 0, i = 0;
	size_t size = 0;
	char **buff = NULL;
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
	buff = malloc(sizeof(char *));
	if (buff == NULL)
	{
		fclose(o);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	buff[0] = NULL;
	while ((getline(&buff[s], &size, o)) != -1)
	{
		s++;
		buff = _realloc(buff, s * sizeof(char *), (s + 1) * sizeof(char *));
		buff[s] = NULL;
	}
	fclose(o);
	check(buff, &h, s);
	while (i <= s)
	{
		free(buff[i]);
		i++;
	}
	free(buff);
	while (h)
	{
		q = h;
		h = h->next;
		free(q);
	}
	return (0);
}
