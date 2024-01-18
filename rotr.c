#include "monty.h"
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
	while (copy->next)
	{
		cp = cp->next;
	}
	cp->next = *head;
	cp->prev->next = NULL;
	cp->prev = NULL;
	(*head)->prev = cp;
	(*head) = cp;
}
