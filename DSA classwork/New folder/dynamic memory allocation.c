#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char name[50], departure[50];
    int id;
    float amt;

}MM;
void read(MM*p,int n)
{
    int i;
    printf("\nEnter the Name,Transaction Number, departure,Amount\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%d%s%f",(p+i)->name,&(p+i)->id,(p+i)->departure,&(p+i)->amt);
    }
}
void display(MM*p,int n)
{
    int i;
    printf("\n  NAME\t\tTRANSACTION NO\t\tDEPARTURE\t\tAMOUNT");
    for(i=0;i<n;i++)
    {
        printf("\n%d.%s\t\t%d\t\t\t%s\t\t%0.2f\n",i+1,(p+i)->name,(p+i)->id,(p+i)->departure,(p+i)->amt);
    }
}
void discount(MM*p,int n)
{
    int i;
    printf("\nCustomers getting discount are:");
    for(i=0;i<n;i++)
    {
        if(((p+i)->id)==25)
            printf("\n%d.%s\n",i+1,(p+i)->name);
    }
}
void total(MM*p,int n)
{
    int i;
    float d;

    {
        if(((p+i)->id)==25)
        {
           for(i=0;i<n;i++)
           d=(p+i)->amt*0.5;
           printf("\nThe discount amounts of customers are:");
           printf("\n NAME\tDISCOUNT\n");
           printf("\n%d.%s\t%0.2f\n",i+1,(p+i)->name,d);
        }
        else
        {
            printf("There are no discounts\n");
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of customers:");
    scanf("%d",&n);
    MM ptr;
    MM*p;
    p=(MM*)calloc(n,sizeof(MM));
    if(p==NULL)
    {
        printf("Memory not allocated.");
    }
    else
    {
        read(p,n);
        display(p,n);
        discount(p,n);
        total(p,n);
    }
    free(p);
    return 0;
}

