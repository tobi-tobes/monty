#include "monty.h"

/**
 * clean_up - removes excess spaces from line
 * @line: string to be split
 *
 * Return: nothing
 */
char *clean_up(char *line)
{
	char buffer[100], *cleaned;
	int i, j = 0, shift = 0;

	while (line[shift] == ' ')
		shift++;

	for (i = shift; line[i] != '\n' && line[i] != '#'; i++)
	{
		if (line[i] == ' ' && line[i + 1] == ' ')
			continue;
		else if (line[i] == ' ' && line[i + 1] == '\n')
			continue;
		else
		{
			buffer[j] = line[i];
			j++;
		}
	}
	buffer[j] = '\0';
	cleaned = malloc((sizeof(char) * strlen(buffer)) + 1);
	if (cleaned == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(head);
		exit(EXIT_FAILURE);
	}
	strcpy(cleaned, buffer);
	return (cleaned);
}

/**
 * execute - executes the given function
 * @buffer: line from file
 * @line_number: line_number
 *
 * Return: nothing
 */
void execute(char *buffer, unsigned int line_number)
{
	int i, length = 0;
	static char *mode = "stack";
	char *arg, *clean;
	instruction_t op_codes[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", nop}, {"sub", sub}, {"div", divd},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, {NULL, NULL}
	};

	clean = clean_up(buffer);
	for (i = 0; op_codes[i].opcode != NULL; i++)
	{
		length = strlen(op_codes[i].opcode);
		if (strncmp(op_codes[i].opcode, clean, length) == 0)
		{
			op_codes[i].f(&head, line_number);
			free(clean);
			return;
		}
	}
	if (strncmp(clean, "stack", 5) == 0 && clean[5] == ' ')
		mode = "stack";
	else if (strncmp(clean, "queue", 5) == 0 && clean[5] == ' ')
		mode = "queue";
	else if (strncmp(clean, "push", 4) == 0 && (clean[4] == ' ' ||
						    clean[4] == '\0'))
		push(&head, line_number, mode, clean);
	else
	{
		arg = strtok(clean, " ");
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number,
			arg);
		free(clean);
		free_list(head);
		exit(EXIT_FAILURE);
	}
	free(clean);
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
		i++;

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

	for (i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++)
	{
		if (buffer[i] != ' ')
			return (0);
	}
	return (1);
}
