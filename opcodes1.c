#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value, i;

	for (i = 0; args[1][i] != '\0'; i++)
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n",
				line_number);
			free_list(head);
			free_array(args);
			exit(EXIT_FAILURE);
		}
	}
	value = atoi(args[1]);
	if (strcmp(mode, "stack") == 0)
		insert(stack, value);
	else if (strcmp(mode, "queue") == 0)
		insert_end(stack, value);
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if ((*stack) != NULL)
		print_list((*stack));
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
			line_number);
		free_list(head);
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
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			line_number);
		free_list(*stack);
		free_array(args);
		exit(EXIT_FAILURE);
	}
	del_top(*stack);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if ((*stack) == NULL || list_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
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
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
