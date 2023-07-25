#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp=NULL;
    char str[5];

    fp=fopen("shaane.txt","a");
    printf("enter the string\n");
    scanf("%s",str);
    if(fp==NULL)
    {
        printf("Error\n");
        return 0;
    }
  fprintf(fp,"%s",str);
  fputs(str,fp);
  fclose(fp);
}
