#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
char s[1000];
int i,kolvo=0;


    char * input_fn = "input.txt";
    char * output_fn = "output.txt";

    FILE *fp_in = fopen(input_fn, "r");
    FILE *fp_out = fopen(output_fn, "w");
    fgets(s,1000,fp_in);

//gets(s);

for (i=0; i <= strlen(s); i++)
{
  if ((s[i] == ' ' || s[i] == '\0' )&& (s[i - 1]=='a')) kolvo++;

}

    printf("%d", kolvo);
    fprintf(fp_out, "%d", kolvo);
    fclose(fp_in);
    fclose(fp_out);

return 0;
}


