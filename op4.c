#include "monty.h"

/**
* f_pop - function that prints the top of the stack
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void func_pop(stack_t **head, unsigned int count)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
* f_pint - function that prints the top of the stack
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void f_pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* f_nop - function that does nothing
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void f_nop(stack_t **head, unsigned int count)
{
	(void) count;
	(void) head;
}
