#include "monty.h"

/**
 * free_list - frees a linked list
 * @head: pointer to top of the list
 *
 * Return: nothing
 */
void free_list(stack_t *head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
		{
			while (head->next != NULL)
				head = head->next;
		}
		while (head->prev != NULL)
		{
			head = head->prev;
			free(head->next);
		}
		free(head);
	}
}

/**
 * list_len - finds the length of a list
 * @h: pointer to list
 *
 * Return: length of the list
 */
size_t list_len(const stack_t *h)
{
	size_t length = 0;

	if (h == NULL)
		return (0);

	if (h->prev != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}
	while (h != NULL)
	{
		length++;
		h = h->next;
	}
	return (length);
}

/**
 * print_list - prints a list
 * @h: pointer to list to be printed
 *
 * Return: length of list
 */
size_t print_list(const stack_t *h)
{
	size_t num = 0;

	if (h == NULL)
		return (0);

	if (h->prev != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}
	while (h != NULL)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}
	return (num);
}
