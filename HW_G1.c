#include <stdio.h>

#define SIZE 256

int main(void)
{


char * message = "aab";
char line[SIZE];
char c;
FILE *fp;



if((fp = fopen("input.txt", "w")) == NULL)
    {
        printf("Error create input file!\n");
        return 1;
    }

    if(fp)
    {
        fputs(message, fp);
        fclose(fp);
    }


    if((fp = fopen("input.txt", "r")) == NULL)
    {
        printf("Error read input file!\n");
        return 1;
    }


    int count = 0;

        for(c = getc(fp); (c != EOF) && (c != '\n'); c = getc(fp))
            line[count++] = c;

    line[count] = '\0';
    fclose(fp);


    if((fp = fopen("output.txt", "w")) == NULL)
    {
        printf("Error create opening output file!");
        return 1;
    }


    for (int i = 0; i < 3; i++)
    {
        if (i)
            fprintf(fp, ", ");
        fprintf(fp, "%s", line);
    }
    fprintf(fp, " %d", count);
    fclose(fp);
    return 0;
}

