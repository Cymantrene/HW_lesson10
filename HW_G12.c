#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
char s[1000];
int i,len=0;
  bool flag= false;

    char * input_fn = "input.txt";
    char * output_fn = "output.txt";

    FILE *fp_in = fopen(input_fn, "r");
    FILE *fp_out = fopen(output_fn, "w");
    fgets(s,1000,fp_in);
    len=strlen(s);

      for(i=0;i<len;i++)
     {
         if(s[i] !=' ')
         {
             fprintf(fp_out, "%c", s[i]);
                flag=true;
         }
         if((s[i] == ' ' && s[i+1] != ' ') && (flag ==true)) fprintf(fp_out, "\n");
     }


    fclose(fp_in);
    fclose(fp_out);

return 0;
}
