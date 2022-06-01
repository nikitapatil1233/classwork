#include<stdio.h>
void read(int n,int a[])
{
    int i;
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int n,int a[])
{
    int i;
    printf("The array elements are :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void max(int n,int a[])
{
    int i,sum=0,r=0,max;
    for(i=0;i<n;i++)
    {
        max=0;
        while(a[i]!=0)
        {
            r=a[i]%10;
            a[i]=a[i]/10;
            if(r>max)
            {
                max=r;
            }
        }
        printf("%d\t",max);
        sum+=max;
    }
    printf("\nSum = %d\n",sum);
}
void main()
{
    int n,a[100];
    printf("enter size:\n");
    scanf("%d",&n);
    read(n,a);
    display(n,a);
    max(n,a);
}
