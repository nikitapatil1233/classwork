#include<stdio.h>
void read(int n,int a[])
{
    int i;
    printf("Tax paid: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void count(int n,int a[])
{
    int i,x=0,y=0,sum=0,avg;
    for(i=0;i<n;i++)
    {
        if(a[i]>250000)
            x++;
        else if(a[i]>=50000&&a[i]<=150000)
            y++;

        sum+=a[i];
    }
    avg=(float)(sum/n);
    printf("\nCount of tax payers who paid more than 2.5 Lakhs is %d\n",x);
    printf("Count of tax payers who paid between 50,000 to 1,50,000 is %d\n",y);
    printf("Average tax collected = %d\n",avg);
}
void main()
{
    int n,a[100];
    printf("Enter number of tax payers\n");
    scanf("%d",&n);
    read(n,a);
    count(n,a);
}
