#include<stdio.h>
void read(int n,int a[])
{
    int i;
    printf("Enter the rank of %d students:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void sort(int n,int a[])
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
        else
            continue;
        }

    }
    printf("The ranks in ascending order:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void max(int n,int a[])
{
    int i,max=a[0],min=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    printf("\nHighest rank :%d\n",min);
    printf("Lowest rank :%d\n",max);
}
void main()
{
    int n,a[100];
    printf("Enter number of students: ");
    scanf("%d",&n);
    read(n,a);
    sort(n,a);
    max(n,a);
}
