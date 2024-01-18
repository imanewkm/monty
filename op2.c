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
 * func_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void func_mul(stack_t **head, unsigned int counter)
{
	stack_t *n;
	int length = 0, i;

	n = *head;
	while (n)
	{
		n = n->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = *head;
	i = n->next->j * n->j;
	n->node->j = i;
	*head = n->node;
	free(n);
}

/**
  *func_nop - nothing
  *@head: stack head
  *@count: line_number
  *Return: no return
 */
void func_nop(stack_t **head, unsigned int count)
{
	(void) count;
	(void) head;
}

/**
 * func_pall - prints the stack
 * @head: stack head
 * @count: no used
 * Return: no return
*/
void func_pall(stack_t **head, unsigned int count)
{
	stack_t *n;
	(void)count;

	n = *head;
	if (n == NULL)
		return;
	while (n)
	{
		printf("%d\n", n->j);
		n = n->next;
	}
}

/**
 * func_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void func_pchar(stack_t **head, unsigned int count)
{
	stack_t *n;

	n = *head;
	if (!n)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (n->j > 127 || n->j < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n->j);
}
