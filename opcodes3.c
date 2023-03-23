#include "monty.h"

/**
 * mod - finds the remainder of the second top /  top element of the stack
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int res;

	if ((*stack) == NULL || list_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free_list(*stack);
		free_array(args);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev != NULL)
	{
		while ((*stack)->prev != NULL)
			(*stack) = (*stack)->prev;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_list(*stack);
		free_array(args);
		exit(EXIT_FAILURE);
	}
	res = ((*stack)->next->n) % ((*stack)->n);
	(*stack)->next->n = res;
	pop(stack, line_number);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			line_number);
		free_list(*stack);
		free_array(args);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev != NULL)
	{
		while ((*stack)->prev != NULL)
		{
			(*stack) = (*stack)->prev;
		}
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number);
		free_list(*stack);
		free_array(args);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top, followed by a new line
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if ((*stack) == NULL)
	{
		printf("\n");
		return;
	}
	if ((*stack)->prev != NULL)
	{
		while ((*stack)->prev != NULL)
			(*stack) = (*stack)->prev;
	}
	while (((*stack)->n > 0 && (*stack)->n <= 127)
	       && (*stack)->next != NULL)
	{
		printf("%c\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}

/**
 * rotl - rotates the stack to the top
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int first;

	(void) line_number;

	if ((*stack) != NULL && list_len((*stack)) > 2)
	{
		if ((*stack)->prev != NULL)
		{
			while ((*stack)->prev != NULL)
			{
				(*stack) = (*stack)->prev;
			}
		}
		first = (*stack)->n;
		pop(stack, line_no);
		insert_end(stack, first);
	}
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	int last;

	(void) line_number;

	if ((*stack) != NULL && list_len((*stack)) > 2)
	{
		if ((*stack)->next != NULL)
		{
			while ((*stack)->next != NULL)
			{
				(*stack) = (*stack)->next;
			}
		}
		last = (*stack)->n;
		(*stack)->prev->next = NULL;
		free((*stack));
		insert(stack, last);
	}
}
