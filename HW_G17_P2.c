#include <stdio.h>
#include <string.h>

void swapChar(char *ch1, char *ch2)
{
	char temp = *ch2;
	*ch2 = *ch1;
	*ch1 = temp;
}

void swapPairs(char *str)
{
	int length = strlen(str);

	int i = 0, j;
	while (i < length)
	{
		while (str[i] == ' ')
		{
			i++;
		}

		j = i + 1;
		while (str[j] == ' ')
		{
			j++;
		}

		if (j >= length)
		{
			break;
		}

		swapChar(&str[i], &str[j]);

		i = j + 1;
	}
}

const int MAX_LINE_SIZE = 1000 + 1;

int main()
{
	char *input_fn = "input.txt";
	char *output_fn = "output.txt";

	char line[MAX_LINE_SIZE];

	FILE *fi = fopen(input_fn, "r");

	fscanf(fi, "%[^\n]", line);

	fclose(fi);

	FILE *fo = fopen(output_fn, "w");

	swapPairs(line);
	fprintf(fo, "%s", line);

	fclose(fo);

	return 0;
}
