#include "monty.h"
/**
 * addnode_func - add node to the h stack
 * @h: h of the stack
 * @n: new_value
 * Return: no return
*/
void addnode_func(stack_t **h, int n)
{

	stack_t *node, *aux;

	aux = *h;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aux)
		aux->prev = node;
	node->n = n;
	node->next_node = *h;
	node->prev = NULL;
	*h = node;
}
/**
* execute_func - executes the opcode
* @stack: h linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int exe_func(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_func}, {"pall", pall_func}, {"pint", pint_func},
				{"pop", pop_func},
				{"swap", swap_func},
				{"add", add_func},
				{"nop", nop_func},
				{"sub", sub_func},
				{"div", div_func},
				{"mul", mul_func},
				{"mod", mod_func},
				{"pchar", pchar_func},
				{"pstr", pstr_func},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
/**
* free_stack - frees a doubly linked list
* @h: h of the stack
*/
void free_stack(stack_t *h)
{
	stack_t *aux;

	aux = h;
	while (h)
	{
		aux = h->next_node;
		free(h);
		h = aux;
	}
}
/**
 * addqueue_func - add node to the tail stack
 * @n: new_value
 * @h: h of the stack
 * Return: no return
*/
void addqueue_func(stack_t **h, int n)
{
	stack_t *node, *aux;

	aux = *h;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error\n");
	}
	node->n = n;
	node->next_node = NULL;
	if (aux)
	{
		while (aux->next_node)
			aux = aux->next_node;
	}
	if (!aux)
	{
		*h = node;
		node->prev = NULL;
	}
	else
	{
		aux->next_node = node;
		node->prev = aux;
	}
}
