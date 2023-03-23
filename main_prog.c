#include "monty.h"

/**
 * main - a UNIX command line interpreter.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *monty_file;
	char line[100];

	head = NULL;
	line_no = 0;
	mode = "stack";
	args = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	printf("Made it!\n");
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	printf("opened file!\n");
	while (fgets(line, 100, monty_file))
	{
		printf("Read a line!\n");
		line_no++;
		printf("Incremented line_no!\n");
		if (check_comms(line) || check_empty(line))
			continue;
		printf("Checked for comments and empty lines!\n");
		args = tokenize(line);
		printf("Tokenized the line!\n");
		execute(args);
		printf("Executed!\n");
		free_array(args);
		printf("Freed arguments array!\n");
	}
	if (ferror(monty_file))
	{
		fprintf(stderr, "Error: Can't read file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fclose(monty_file);
	free_list(head);

	return (0);
}
