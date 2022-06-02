#include<stdio.h>
struct transactions
{
    int rec,hotel;
};
void read(struct transactions s[100],int N);
void add(struct transactions s[100],int N);
void total(struct transactions s[100],int N,int a[100]);
int highest(int a[100],int N);
int main()
{
    struct transactions s[100];
    int N,a[100],l;
    printf("Enter the number of transactions\n");
    scanf("%d",&N);
    read(s,N);
    add(s,N);
    total(s,N,a);
    l=highest(a,N);
    printf("the highest transaction is %d",l);
    return 0;
}
void read(struct transactions s[100],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("\nEnter the recharge and hotel payment\n");
        scanf("%d%d",&s[i].rec,&s[i].hotel);
    }
}
void add(struct transactions s[100],int N)
{
    int i;
    int sum=0;
    for(i=0;i<N;i++)
    {
        sum=sum+s[i].rec;
    }
    printf("the total amount spent on recharge based transactions is %d\n",sum);

}
void total(struct transactions s[100],int N,int a[100])
{
    int i;
    for(i=0;i<N;i++)
    {
        a[i]=s[i].rec+s[i].hotel;
    }
}
int highest(int a[100],int N)
{
    int i,l;
    l=a[0];
    for(i=1;i<N;i++)
    {
        if(l<a[i])
            l=a[i];
    }
    return l;
}
