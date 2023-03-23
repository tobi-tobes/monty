#include "monty.h"

/**
 * main - a command line interpreter for monty bytecodes
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *monty_file;
	char line[100];
	unsigned int line_no = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, 100, monty_file))
	{
		line_no++;
		if (check_comms(line) || check_empty(line))
			continue;
		execute(line, line_no);
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
