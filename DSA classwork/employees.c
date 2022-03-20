#include<stdio.h>
#include<string.h>
struct employee
{
    int id;
    char name[50];
};
typedef struct employee e1;

 void read( e1 a[],int n)
 {
     int i;
     printf("enter the employees id and name\n");
     for(i=0;i<n;i++)
     {
         scanf("%d%s",&a[i].id,a[i].name);
     }
 }
  void display( e1 a[],int n)
  {
      int i;
     printf("enter the employees id and name\n");
     for(i=0;i<n;i++)
     {
         printf("%d %s", a[i].id,a[i].name);
     }

  }
  void main()
  {
      int n;
      printf("enter the n value\n");
      scanf("%d",&n);
       e1 a[50];
      read(a,n);
      display(a,n);
  }
