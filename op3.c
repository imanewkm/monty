#include "monty.h"
#define MIN_ASCII 1
#define MAX_ASCII 127
/**
 * pop_from_stack - prints the top
 * @h: stack head
 * @cnt: line_number
 * Return: no return
*/
void pop_from_stack(stack_t **h, unsigned int cnt)
{
	stack_t *head;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", cnt);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	*h = head->next;
	free(head);
}

/**
 * print_string - prints the string starting at the top of the stack,
 * followed by a new
 * @h: stack head
 * @cnt: line_number
 * Return: no return
*/
void print_string(stack_t **h, unsigned int cnt)
{
	stack_t *head;
	(void)cnt;

	head = *h;
	while (head)
	{
		if (head->n > MAX_ASCII || head->n <= MIN_ASCII)
		{
			break;
		}
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}

/**
 * print_top_of_stack - prints the top
 * @h: stack head
 * @cnt: line_number
 * Return: no return
*/
void print_top_of_stack(stack_t **h, unsigned int cnt)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", cnt;
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}

/**
 * push - add node to the stack
 * @h: stack head
 * @cnt: line_number
 * Return: no return
*/
void push(stack_t **h, unsigned int cnt)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", cnt);
			fclose(bus.file);
			free(bus.content);
			free_stack(*h);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", cnt);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(h, n);
	else
		addqueue(h, n);
}

/**
  *func_rotr- rotates the stack to the bottom
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void func_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
