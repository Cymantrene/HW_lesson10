#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp_in, *fp_out;
    int kolvo,povtor_s1,num_symbol;
    char s1[100];
    char s2[100];
    fp_in=fopen("input.txt","r");
    fp_out=fopen("output.txt","w");

    fscanf(fp_in,"%s%s",s1,s2);


    for (int i=0;i<strlen(s1);i++)
    {
        kolvo=0;
        povtor_s1=0;

        for (int k=0;k<strlen(s1);k++)
        {
            if ((s1[k]==s1[i])&&(k!=i))
            {
                povtor_s1++;
            }
        }

    	for (int j=0;j<strlen(s2);j++)
        {
            if (s1[i]==s2[j])
            {
    	        kolvo++;
                num_symbol=j;
            }
            if ((kolvo==1)&&(j==(strlen(s2)-1))&&(povtor_s1==0))
            {
    	        fprintf(fp_out,"%c ",s2[num_symbol]);
            }

        }

    }
    fclose(fp_in);
    fclose(fp_out);
	return 0;
}
