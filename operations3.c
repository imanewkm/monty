#include "monty.h"
/**
  *nop_func - nothing
  *@h: stack h
  *@counter: line_number
  *Return: no return
 */
void nop_func(stack_t **h, unsigned int counter)
{
	(void) counter;
	(void) h;
}

/**
 * pchar_func - prints the char at the top of the stack,
 * followed by a new line
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void pchar_func(stack_t **h, unsigned int counter)
{
	stack_t *head;

	head = *h;
	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	if (head->n > 127 || head->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", head->n);
}

/**
 * pstr_func - prints the string starting at the top of the stack,
 * followed by a new
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void pstr_func(stack_t **h, unsigned int counter)
{
	stack_t *head;
	(void)counter;

	head = *h;
	while (head)
	{
		if (head->n > 127 || head->n <= 0)
		{
			break;
		}
		printf("%c", head->n);
		head = head->next_node;
	}
	printf("\n");
}
