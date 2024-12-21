#include <stdio.h>
#include <string.h>


int main()
{

    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char res[1000] = {'\0'};
    char str[1000];
    char buf[1000];
    char c;
    int i=0, j=0;
    FILE *fp_in = fopen(input_fn, "r");
    FILE *fp_out = fopen(output_fn, "w");
    fgets (str, 1000, fp_in);
    while (str[i] != '\0')
    {
        buf[i]= str[i];
        i++;
    }
    j = 0;
    i++;
     for (i=0; i< strlen(buf); i++)
    {
        c = buf[i];
        if (strchr(res,c) == NULL && c != ' ')
        {
            res[j] = c;
            ++j; // += 1;
        }
    }
    res[j] = '\0';
    puts(res);
    fprintf(fp_out, "%s", res);
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
