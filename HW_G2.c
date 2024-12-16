#include <stdio.h>
#include <string.h>

int main()
{
int i, n;

    FILE * fp_in = fopen("input.txt", "r");
    FILE * fp_out = fopen("output.txt", "w");

    fscanf(fp_in, "%d", &n);

    char str[n + 2];
    char c = 'A';
    char c_num = '2';
    for (i = 0; i < n; i++)
    {
        if (i%2==0)
            str[i] = c++;
        else
        {
            str[i] = c_num;
            if (c_num == '8')
                c_num = '2';
            else
                c_num += 2;
        }
    }
    str[i] = '\0';
    fprintf(fp_out, "%s", str);
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}

