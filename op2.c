#include "monty.h"
/**
 * func_mod - computes
 * @head: head of stack
 * @count: line num
 * Return: Always 0 (Success)
 */
void func_mod(stack_t **head, unsigned int count)
{
	stack_t *n;
	int length = 0, i;

	n = *head;
	while (n)
	{
		n = n->node;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	i = n->node % n->j;
	n->next->j = i;
	*head = n->node;
	free(n);
}

/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
  *f_nop- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
