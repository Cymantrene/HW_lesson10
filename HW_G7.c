#include <stdio.h>

#define SIZE 10000

int main()
{

   char str[SIZE];
    int i,let_b, let_s;
    FILE *fp_in = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");

    fgets(str, SIZE, fp_in);




    let_s = 0;
    let_b = 0;
    for (i=0; str[i]!='\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            let_s += 1;
        else
            if (str[i] >= 'A' && str[i] <= 'Z')
            let_b += 1;


    fprintf(fp_out, "%d %d", let_s, let_b);
    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
