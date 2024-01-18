#include "monty.h"
#define MIN_ASCII 1
#define MAX_ASCII 127
/**
 * func_pop - prints the top
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void func_pop(stack_t **head, unsigned int count)
{
	stack_t *stack;

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
	free(stack);
}

/**
 * func_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @count: line_number
 * Return: no return
*/

void func_pstr(stack_t **head, unsigned int count)
{
	stack_t *stack;
	(void)count;

	stack = *head;
	while (stack)
	{
		if (stack->n > 127 || stack->n <= 0)
		{
			break;
		}
		printf("%c", stack->n);
		stack = stack->next;
	}
	printf("\n");
}

/**
 * func_pint - prints the top
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void func_pint(stack_t **head, unsigned int count)
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
 * func_push - add node to the stack
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void func_push(stack_t **head, unsigned int count)
{
	int n, j = 0, f = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				f = 1; }
		if (f == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
/**
  *func_rotr - rotates the stack to the bottom
  *@head: stack head
  *@count: line_number
  *Return: no return
 */
void func_rotr(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *cp;

	cp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (cp->next)
	{
		cp = cp->next;
	}
	cp->next = *head;
	cp->prev->next = NULL;
	cp->prev = NULL;
	(*head)->prev = cp;
	(*head) = cp;
}
