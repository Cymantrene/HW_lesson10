#include <stdio.h>

#define SIZE 1000

int main (void)
{

    char line[SIZE];
    char temp_buf[SIZE];

    int count=0;

    FILE *fp_in = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");

    fgets(temp_buf, SIZE, fp_in);

    while (temp_buf[count] != '\0')
    {
        line[count]= temp_buf[count];
        count++;
    }

    --count;
    for (int i=0; i<count; i++)
     {
         if (line[i] == line[count])
         fprintf(fp_out, "%d ", i);
     }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
