#include <stdio.h>
#include <string.h>
//#include <locale.h>
int main()
{
//system("chcp 1251");
//setlocale(LC_ALL, "Rus");
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char s[10000];
char res[10000];
int i, j=0, index_max, max, count, len;

 FILE *fp_in = fopen(input_fn, "r");
 FILE *fp_out = fopen(output_fn, "w");

fgets (s, 10000, fp_in);
len = strlen(s);
max = 0;
index_max = 0;
count = 0;
for (i=0; i<len; i++)
    if (s[i] != ' ') count++;
    else
    {
        if (count > max)
        {
            max = count;
            index_max = i - count;
        }
        count = 0;
    }

if (count > max) {  
    max = count;
    index_max = i - count;
}
max += index_max; 
//printf("\nThe long word:\n");
for (i=index_max; i<max; i++) 
    //putchar(s[i]); 
   {
       res[j++]= s[i];
   }
    res[j] = '\0';
   fprintf(fp_out, "%s", res);

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
