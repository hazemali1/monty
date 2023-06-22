#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void check(char **buff, stack_t **h, int p);
void _push(char **Buf, stack_t **h, int l, char **buff, int t);
void _pall(stack_t **h);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *fill_all_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void _pint(stack_t **h, char **buff, int s, int l, char **Buf);
void _pop(stack_t **h, char **buff, int s, int l, char **Buf);

#endif
