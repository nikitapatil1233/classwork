#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
typedef struct node * NODE;
NODE getnode()
{
    NODE newn;
    newn=(NODE)malloc(sizeof(struct node));
    if(newn==NULL)
        printf("Memory allocation failed\n");
    return newn;
}
void read(NODE newn)
{
    scanf("%d",&newn->data);
    newn->next=NULL;
    newn->prev=NULL;
}
NODE insert_end(NODE head)
{
    NODE newn=getnode();
    if(newn==NULL)
        return head;
    read(newn);
    if(head==NULL)
    {
        head=newn;
        return head;
    }
    else
    {
        NODE cur=head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=newn;
        newn->prev=cur;
        return head;
    }
}
NODE compare(NODE head)
{
    NODE newn;
    if(head==NULL)
    {
        head=newn;
        return head;
    }
    else
    {
        int count;
        NODE cur=head;
        if(cur->data>=150&&cur->data<cur->next->data)
        {
            printf("%d ",cur->data);
            count++;
        }
        cur=cur->next;
        while(cur->next!=NULL)
        {
            if(((cur->data)<(cur->next->data))&&((cur->data)>(cur->prev->data)))
            {
                printf("%d ",cur->data);
                count++;
            }
            cur=cur->next;
        }
        if(cur->data>=150&&cur->data>cur->prev->data)
        {
            printf("%d",cur->data);
            count++;
        }
        printf("\n%d",count);
    }
}
void main()
{
    NODE head=NULL;
    int n,i;
    printf("Enter the number of candidates : ");
    scanf("%d",&n);
    if(n>=1&&n<=100)
    {
        for(i=0;i<n;i++)
        {
            head=insert_end(head);
        }
        head=compare(head);
    }
}
