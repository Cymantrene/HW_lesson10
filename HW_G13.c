#include <stdio.h>
#include <string.h>
#define SIZE 1000

void plus_html(char *line,  char *html)
{
	char *dot = strrchr(line, '.');
	char *slash = strrchr(line, '/');

	if (dot != NULL && slash != NULL)
	{
		int posDot = dot - line + 1;
		int posSlash = slash - line + 1;
		if (posDot > posSlash)
		{
			*dot = '\0';
		}
	}

	strcat(line, html);
}


int main()
{
	char *input_fn = "input.txt";
	char *output_fn = "output.txt";
	char *html = ".html";

	char line[SIZE];

	FILE *fp_in = fopen(input_fn, "r");
    FILE *fp_out = fopen(output_fn, "w");
	fgets(line,SIZE,fp_in);

	plus_html(line, html);
	fprintf(fp_out, "%s", line);
    fclose(fp_in);
	fclose(fp_out);

	return 0;
}
