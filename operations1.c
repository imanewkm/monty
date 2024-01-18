#include "monty.h"
/**
 * add_func - adds the top two elements of the stack.
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void add_func(stack_t **h, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	aux = head->n + head->next_node->n;
	head->next_node->n = aux;
	*h = head->next_node;
	free(head);
}

/**
  *sub_func - sustration
  *@h: stack h
  *@counter: line_number
  *Return: no return
 */
void sub_func(stack_t **h, unsigned int counter)
{
	stack_t *aux;
	int sus, n;

	aux = *h;
	for (n = 0; aux != NULL; n++)
		aux = aux->next_node;
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	aux = *h;
	sus = aux->next_node->n - aux->n;
	aux->next_node->n = sus;
	*h = aux->next_node;
	free(aux);
}

/**
 * mul_func - multiplies the top two elements of the stack.
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void mul_func(stack_t **h, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	aux = head->next_node->n * head->n;
	head->next_node->n = aux;
	*h = head->next_node;
	free(head);
}

/**
 * div_func - divides the top two elements of the stack.
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void div_func(stack_t **h, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	aux = head->next_node->n / head->n;
	head->next_node->n = aux;
	*h = head->next_node;
	free(head);
}

/**
 * mod_func - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void mod_func(stack_t **h, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	aux = head->next_node->n % head->n;
	head->next_node->n = aux;
	*h = head->next_node;
	free(head);
}
