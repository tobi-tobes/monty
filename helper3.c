#include "monty.h"

/**
 * insert - inserts a node at the beginning of a list
 * @head: pointer to pointer to top of the list
 * @n: value to be inserted
 *
 * Return: nothing
 */
void insert(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*head);
		free_array(args);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	if ((*head) == NULL)
	{
		(*head) = new_node;
		new_node->next = NULL;
	}
	else if ((*head) != NULL && (*head)->prev == NULL)
	{
		new_node->next = (*head);
		(*head)->prev = new_node;
		(*head) = new_node;
	}
	else if ((*head) != NULL && (*head)->prev != NULL)
	{
		while ((*head)->prev != NULL)
			(*head) = (*head)->prev;
		new_node->next = (*head);
		(*head)->prev = new_node;
		(*head) = new_node;
	}
}

/**
 * insert_end - inserts a node at the end of a list
 * @head: pointer to pointer to top of the list
 * @n: value to be inserted
 *
 * Return: nothing
 */
void insert_end(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	temp = (*head);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*head);
		free_array(args);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;
	if (temp == NULL)
	{
		(*head) = new_node;
		new_node->prev = NULL;
		return;
	}
	if (temp->next != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	new_node->prev = temp;
	temp->next = new_node;
}

/**
 * del_top - deletes the node at the top of the list
 * @head: pointer to list
 *
 * Return: nothing
 */
void del_top(stack_t *head)
{
	stack_t *temp;

	temp = head;
	if (temp->prev != NULL)
	{
		while (temp->prev != NULL)
			temp = temp->prev;
	}
	if (temp->next == NULL && temp->prev == NULL)
		head = NULL;
	else if (temp->prev == NULL && temp->next != NULL)
	{
		head = temp->next;
		temp->next->prev = NULL;
	}
	free(temp);
}
