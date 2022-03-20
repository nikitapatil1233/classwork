
#include<stdio.h>
#include<string.h>
typedef struct employee
{
    char name[500];
    int id;
}
emp;
void read(emp*a[],int n)
{
    int i;
    printf("Enter the name and id :\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%d",a[i]->name,&a[i]->id);
    }
}
void display(emp*a[],int n)
{
    int i;
    printf("the name and id are :\n");
    for(i=0;i<n;i++)
    {
        printf("%s\n%d\n",a[i]->name,a[i]->id);
    }
}
void main()
{
    int n;
    printf("Enter the number of employees\n");
    scanf("%d",&n);
    emp a[100];
    read(&a,n);
    display(&a,n);
}
