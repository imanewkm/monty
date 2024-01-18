#include "monty.h"
/**
  *func_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void func_rotl(stack_t **head,  __attribute__((unused)) unsigned int count)
{
	stack_t *tmp = *head, *i;

	if (*head == NULL || (*head)->next_node == NULL)
	{
		return;
	}
	i = (*head)->next;
	i->prev = NULL;
	while (tmp->next_node != NULL)
	{
		tmp = tmp->next_node;
	}
	tmp->next_node = *head;
	(*head)->next_node = NULL;
	(*head)->prev = tmp;
	(*head) = i;
}
/**
  *func_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void func_sub(stack_t **head, unsigned int count)
{
	stack_t *i;
	int s, node;

	i = *head;
	for (node = 0; i != NULL; node++)
		i = i->next_node;
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	i = *head;
	s = i->next_node->j - i->j;
	i->next_node->j = s;
	*head = i->next_node;
	free(i);
}

/**
 * func_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void func_swap(stack_t **head, unsigned int counter)
{
	stack_t *n;
	int length = 0, i;

	n = *head;
	while (n)
	{
		n = n->next_node;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = *head;
	i = n->j;
	n->j = n->next_node->j;
	n->next_node->j = i;
}
