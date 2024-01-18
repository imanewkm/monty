#include "monty.h"

/**
* f_pstr - function that prints the string starting at the top of the stack,
* followed by a new
* @head: head of stack
* @count: line count
*
* Return: nothing
*/
void func_pstr(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
