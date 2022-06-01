#include<stdio.h>
void read(int n,int a[])
{
    int i;
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void reverse(int n, int a[])
{
    int i,temp;
    for(i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void main()
{
    int n,a[100];
    printf("Enter size: ");
    scanf("%d",&n);
    read(n,a);
    reverse(n,a);
}

