#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	mode = "stack";
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: stack to be pushed to
 * @line_number: current line_number
 *
 * Return: nothing or EXIT_FAILURE
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	mode = "queue";
}
