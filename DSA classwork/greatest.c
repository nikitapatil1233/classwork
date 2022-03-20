#include<stdio.h>
int large(int *x,int *y)
{
    int *l;
    if(*x>*y)
        l=x;
    else
        l=y;
    return l;
}
void main()
{
    int m,n,*x,*y,*l;
    printf("Enter two number:\n");
    scanf("%d%d",&m,&n);
    x=&m;
    y=&n;
    l=large(x,y);
    printf("Largest : %d",*l);
}
