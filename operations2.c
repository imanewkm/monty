#include "monty.h"
/**
 * push_func - add node to the stack
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void push_func(stack_t **h, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*h);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode_func(h, n);
	else
		addqueue_func(h, n);
}

/**
 * pall_func - prints the stack
 * @h: stack h
 * @counter: no used
 * Return: no return
*/
void pall_func(stack_t **h, unsigned int counter)
{
	stack_t *head;
	(void)counter;

	head = *h;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next_node;
	}
}

/**
 * pint_func - prints the top
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void pint_func(stack_t **h, unsigned int counter)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}

/**
 * pop_func - prints the top
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void pop_func(stack_t **h, unsigned int counter)
{
	stack_t *head;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	*h = head->next_node;
	free(head);
}

/**
 * swap_func - adds the top two elements of the stack.
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void swap_func(stack_t **h, unsigned int counter)
{
	stack_t *head;
	int length = 0, aux;

	head = *h;
	while (head)
	{
		head = head->next_node;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	aux = head->n;
	head->n = head->next_node->n;
	head->next_node->n = aux;
}
