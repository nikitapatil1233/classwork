#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE*fp;
    char ch;
    fp=fopen("sample.txt","w");
    if(fp==NULL)
    {
        printf("error in opening a file");
        exit(0);
    }
    printf("input some text\n");
    while ((ch=getchar())!=EOF)
        fputc(ch,fp);
    fclose(fp);
    printf("the file contains\n");
    fp=fopen("sample.txt","r");
    while ((ch=fgetc(fp)) !=EOF)
        putchar(ch);
    fclose(fp);
    }

