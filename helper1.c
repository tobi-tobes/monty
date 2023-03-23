#include "monty.h"

/**
 * tokenize - splits up a string into an array of arguments
 * @line: string to be split
 *
 * Return: array of arguments or EXIT_FAILURE
 */
char **tokenize(char *line)
{
	char *portion, buffer[100], **tokens;
	int i, j = 0, count = 0;

	for (i = 0; line[i] != '\n' && line[i] != '#'; i++)
	{
		if (i == 0 && line[i] == ' ')
			continue;
		else if (i != 0 && line[i] == ' ')
		{
			if (line[i + 1] == ' ' && line[i - 1] == ' ')
				continue;
		}
		else
		{
			buffer[j] = line[i];
			j++;
		}
	}
	printf("Created a buffer!\n");
	printf("%s\n", buffer);
	tokens = malloc(sizeof(char *) * 2);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(head);
		free_array(args);
		exit(EXIT_FAILURE);
	}
	printf("Made it2!\n");
	for (portion = buffer; count < 2; portion = NULL)
	{
		portion = strtok(portion, " ");
		tokens[count] = malloc((sizeof(char) * strlen(portion)) + 1);
		if (tokens[count] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_list(head);
			free_array(args);
			exit(EXIT_FAILURE);
		}
		strcpy(tokens[count], portion);
		count++;
	}
	printf("Made it3!\n");
	return (tokens);
}

/**
 * execute - executes the given function
 * @args: array of arguments
 *
 * Return: nothing
 */
void execute(char **args)
{
	int i;
	instruction_t op_codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divd},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	for (i = 0; op_codes[i].opcode != NULL; i++)
	{
		if (strcmp(op_codes[i].opcode, args[0]) == 0)
		{
			op_codes[i].f(&head, line_no);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_no, args[0]);
	free_list(head);
	free_array(args);
	exit(EXIT_FAILURE);
}

/**
 * check_comms - checks if a line is commented out
 * @buffer: line to check
 *
 * Return: 1 if the line is a comment, else 0
 */
int check_comms(char *buffer)
{
	int i = 0;
	char check;

	if (buffer[0] == '#')
		return (1);

	while (buffer[i] == ' ')
	{
		i++;
	}
	check = buffer[i];
	if (check == '#')
		return (1);

	return (0);
}

/**
 * check_empty - checks if a line is empty
 * @buffer: line to check
 *
 * Return: 1 if the line is empty, else 0
 */
int check_empty(char *buffer)
{
	int i;

	if (buffer[0] == '\n' || buffer[0] == '\0')
		return (1);

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] != ' ')
			return (0);
	}
	return (1);
}
