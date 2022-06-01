//*read and display*//
#include<stdio.h>
#include<stdlib.h>
void read(int a[],int n);
void disp(int a[],int n);
void sum(int a[],int n);
int main()
{
    int a[100],i,n;

    printf("enter the size of array");
    scanf("%d",&n);

    if(n<=0||n>100)
    {
        printf("invalid array size");
        exit(0);
    }
    read(a,n);
    disp(a,n);
    sum(a,n);

}

    void read(int a[],int n)
    {
        int i;

        printf("enter the elements in array");

        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
    }

    void disp(int a[],int n)
    {
        int i;

        printf("display elements in an array");
        for(i=0;i<n;i++)
        {
            printf("%d\n",a[i]);
        }
    }

    void sum(int a[],int n)
    {
        int i,largest=0,rem,num,sum=0;

         for(i=0;i<0;i++)
         {
             num=a[i];
             while(num>0)
             {
                 rem=num%10;
                 {
                     if(largest>rem)
                     {
                         largest=rem;
                     }
                     num=num/10;
                 }
                 sum=sum+largest;
             }
             printf("sum=%d\n",sum-1);
         }





    }













