#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void add(stack_t **stack, unsigned int line_number)
{
	int res;

	if (list_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev != NULL)
	{
		while ((*stack)->prev != NULL)
			(*stack) = (*stack)->prev;
	}
	res = ((*stack)->n) + ((*stack)->next->n);
	(*stack)->next->n = res;
	pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub - subtracts the top element from the second top element of the stack
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int res;

	if (list_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev != NULL)
	{
		while ((*stack)->prev != NULL)
			(*stack) = (*stack)->prev;
	}
	res = ((*stack)->next->n) - ((*stack)->n);
	(*stack)->next->n = res;
	pop(stack, line_number);
}

/**
 * divd - divides the second top element by the top element of the stack
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void divd(stack_t **stack, unsigned int line_number)
{
	int res;

	if (list_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free_list(*stack);
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
		exit(EXIT_FAILURE);
	}
	res = ((*stack)->next->n) / ((*stack)->n);
	(*stack)->next->n = res;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element with the top element of the stack
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int res;

	if (list_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev != NULL)
	{
		while ((*stack)->prev != NULL)
			(*stack) = (*stack)->prev;
	}
	res = ((*stack)->next->n) * ((*stack)->n);
	(*stack)->next->n = res;
	pop(stack, line_number);
}
