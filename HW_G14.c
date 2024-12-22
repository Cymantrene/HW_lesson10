#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[1000], *p = s;
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char  end = '!';
    FILE *fp_in = fopen(input_fn, "r");
    FILE *fp_out = fopen(output_fn, "w");
    fgets(s,1000,fp_in);


    fprintf(fp_out, "Hello, " );

    while( *p != ' ' ) p++;
    while( *++p != ' ' ) fputc( *p, fp_out);
    fputc( *p, fp_out );
    p = s;
    while( *p != ' ' ) fputc( *p++, fp_out );

    fputc( end, fp_out );
    fclose(fp_in);
    fclose(fp_out);
    //printf( ".\n" );


    return 0;
}
