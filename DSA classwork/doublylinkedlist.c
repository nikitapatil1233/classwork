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
    printf("Enter details\n");
    scanf("%d",&newn->data);
    newn->next=NULL;
    newn->prev=NULL;
}
NODE insert_front(NODE head)
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
        head->prev=newn;
        newn->next=head;
        head=newn;
        return head;
    }
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
NODE insert_specific(NODE head)
{
    int loc,i=1;
    printf("Enter location:\n");
    scanf("%d",&loc);
    NODE newn ;
    NODE cur=head,p=NULL;
    if(head == NULL&&loc>1)
    {
        printf("List is empty\n");
    }
    if(loc==1)
    {
        head=insert_front(head);
    }
    else
    {
        newn=getnode();
        while(cur->next!=NULL&&i!=loc)
        {
            p=cur;
            cur=cur->next;
            i++;
        }
        if(loc>i+1)
            printf("cannot insert\n");
        else if(loc==i+1)
        {
            read(newn);

            cur->next=newn;
            newn->prev=cur;
        }
        else
        {
            read(newn);
            p->next=newn;
            newn->prev=p;
            newn->next=cur;
            cur->prev=newn;
        }
    }
    return head;
}
void display(NODE head)
{
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        NODE cur=head;
        while(cur!=NULL)
        {
            printf("%d\n",cur->data);
            cur=cur->next;
        }
    }
}
void main()
{
    NODE head=NULL;
    int choice;
    while(1)
    {
        printf("1.Insert front\n2.Insert end\n3.display\n4.insert specific\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert_front(head);
                    break;
            case 2:head=insert_end(head);
                    break;
            case 3: display(head);
                    break;
            case 4: head=insert_specific(head);
                    break;
            case 5: exit(0);
                    break;
            default:printf("Invalid\n");
        }
    }
}
