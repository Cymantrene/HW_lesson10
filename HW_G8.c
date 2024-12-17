#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define SIZE 10000

int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(int argc,char *argv[])
{

    FILE *fp_in = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");



char str[SIZE];
fgets(str, SIZE, fp_in);
char *ptr = str;

int temp[SIZE];
int i =0;
while (*ptr)
    {
    if ( isdigit(*ptr) )
        {

            int val = (int)strtol(ptr,&ptr, 10); // Read number
            temp[i] = val;
            i++;

        } else
            {

                ptr++;
            }
    }
    qsort(temp, i, sizeof(temp[0]), comp);
    for(int j=0; j<i; j++) fprintf(fp_out, "%d ", temp[j]);

    fclose(fp_in);
    fclose(fp_out);
return 0;
}
