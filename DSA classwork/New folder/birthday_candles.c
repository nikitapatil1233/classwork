#include<stdio.h>
#include<stdlib.h>

struct candles
{
    int height;
    struct candles *next, *prev;
};
typedef struct candles *NODE;

//function prototypes.
NODE getnewnode();

NODE insert_end_cdll(NODE head);

void display(NODE head);

NODE tallest(NODE head);

int main()
{
    int i , n;
    NODE head=NULL;
    printf("Enter the age\n");
    scanf("%d", &n);
    for(i=0;i<n;i++)
        head= insert_end_cdll(head);
   display(head);
   head=tallest(head);
    return 0;
}

NODE getnewnode()
{
    NODE newn = (NODE)malloc(sizeof(struct candles));
    if(newn == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        printf("Enter the heights of candles\n");
        scanf("%d", &newn->height);
        newn->next = newn;
        newn->prev = newn;
    }
    return newn;
}
NODE insert_end_cdll(NODE head)
{
    NODE cur=NULL;
    NODE newn = getnewnode();
    if(head==NULL)
        head=newn;
    else
    {
        cur = head->prev;
        cur->next = newn;
        newn->prev = cur;
        newn->next = head;
        head->prev = newn;
    }
    return head;
}
void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
        printf(" empty\n");
    else
    {
        printf("the heights of candles are\n");
        cur=head;
        do
        {
            printf("%d ", cur->height);
            cur = cur->next;
        }while(cur != head);
    }
}
NODE tallest(NODE head)
{
    NODE cur=head;
    int tall=0,count=0;
    do
    {
        if(cur->height>tall)
        {
           tall=cur->height;
        }
        cur=cur->next;
    }
    while(cur!=head);
    printf("\n\n tallest candle is %d\n",tall);
    cur=head;
    do
    {


        if(cur->height==tall)
    {
        count++;
    }
         cur=cur->next;

    }
    while(cur!=head);
    printf("\n number of candles blown is %d\n",count);
    return head;
}
