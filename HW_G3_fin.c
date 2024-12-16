#include <stdio.h>

#define SIZE 255

int main (void)
{
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char line[SIZE];
    char c;




    FILE *fp_in = fopen(input_fn, "r");
    int count = 0;

    while(((c = getc(fp_in)) != EOF) && (c != '\n'))
        line[count++] = c;
    line[count] = '\0';

    FILE *fp_out = fopen(output_fn, "w");

    --count;
    for (int i=0; i<count; i++)
        if (line[i] == line[count])
            fprintf(fp_out, "%d ", i);

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
