#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include<stdio.h>
int main()
{
    int i,n,sum=0,sum1=0;
    int a[20];
    scanf("%d",&n);
    if(n>0)
    {
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            sum=sum+a[i];

        }

    }
    printf("Sum of even numbers=%d\n",sum);
    for(i=0;i<n;i++)
    {
        if(a[i]%2!=0)
        {
            sum1=sum1+a[i];
        }
    }
    printf("Sum of odd numbers=%d\n",sum1);
    }
    else
        printf("Invalid input");
    return 0;
}
