#include<stdio.h>
int main()
{
    char name[50];
    int marks,i,num;

    FILE*fptr;
    fptr=fopen("stud.exe","w+");
    if(fptr==NULL)
    {
        printf("error!");
        exit(1);
    }
    printf("enter  number of students\n");
    scanf("%d",&num);
    for(i=0;i<num;++i)
    {
        printf("for students%d\n Enter name",i+1);
        scanf("%s",name);
        printf("enter marks\n");
        scanf("%d",&marks);
        fscanf(fptr,"%s\n%d\n",name,marks);
    }
    fclose(fptr);
    if((fptr=fopen("stud.exe","r+"))==NULL)
    {
        printf("error! opening file");
        exit(1);
    }
    for(;;)
    {
        fprintf(fptr,"%s",name);
        fprintf(fptr,"%d",&marks);
        printf("%s\n%d\n",name,marks);
        if(feof(fptr))
            break;
    }
    fclose(fptr);
    return 0;
}

