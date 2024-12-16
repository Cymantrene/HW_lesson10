#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main()
{
    char string[SIZE];
    int count=0;

    FILE *fp_in = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");

    fgets(string, SIZE, fp_in);

    for(int i=0; i<strlen(string); i++)
    {
        switch(string[i])
        {
        case 'a':
            string[i] = 'b';
            count++;
            break;
        case 'b':
            string[i] = 'a';
            count++;
            break;
        case 'A':
            string[i] = 'B';
            count++;
            break;
        case 'B':
            string[i] = 'A';
            count++;
            break;
        }
    }

    fprintf(fp_out, "%s", string);
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}

