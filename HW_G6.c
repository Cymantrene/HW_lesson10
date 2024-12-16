
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#define SIZE 1024


int is_palindrome(char *str)
{

    int left = 0;

    int right = strlen(str) - 1;

    while (left < right) {

        if (str[left] != str[right]) {
            return 0;
        }

        left++;
        right--;
    }
    return 1;
}

int main()
{
    char str[SIZE];

    FILE *fp_in = fopen("input.txt", "r");
    FILE *fp_out = fopen("output.txt", "w");

    fscanf(fp_in, "%s", str);
    fclose(fp_in);

   if(is_palindrome(str)) fprintf(fp_out, "%s", "YES");
    else fprintf(fp_out, "%s", "NO");
    fclose(fp_out);
    return 0;
}
