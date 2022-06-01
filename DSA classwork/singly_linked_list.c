#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;

};
typedef struct node* NODE;
NODE getnode()
{
    NODE newn;
    newn=(NODE)malloc(sizeof(struct node));
    if(newn==NULL)
        printf("no memory allocated\n");
    return newn;
}

void read(NODE newn)
{
    printf("enter details");
    scanf("%d",&newn->data);
    newn->next=NULL;

}
NODE insert_front(NODE head)
{
    NODE newn=getnode();
    read(newn);
    if(head==NULL)
        return newn;
    newn->next=head;
    head=newn;
    return head;
}
NODE insert_end(NODE head)
{
    NODE newn=getnode();
    if(newn==NULL)
        return head;
    read(newn);
    if(head==NULL)
        return newn;
    else
    {
        NODE cur=head;
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=newn;
        return head;
    }
}
NODE delete_front(NODE head)
{
    if(head==NULL)
    {
        printf("empty list");
        return head;
    }
    else
    {
        NODE cur=head;
        head=head->next;
        free(cur);
        return head;
    }
}
NODE delete_end(NODE head)
{
    if(head==NULL)
    {
        printf("list is empty");
        return head;
    }
    else if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        NODE prev=NULL;
        NODE cur=head;
        while(cur->next!=NULL)
        {
            prev=cur;
            cur=cur->next;
        }
        free(cur);

        prev->next=NULL;
        return head;
    }
}
void display(NODE head)
{
    if(head==NULL)
        printf("empty list");
    else
    {
        NODE cur=head;
        while(cur!=NULL)
        {
            printf("%d",cur->data);
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
       printf("1.insert front\n2.insert end\n3.delete front\n4.delete end\n5.display\n6.exit");
       scanf("%d",choice);
       switch(choice)
       {
           case 1: head=insert_front(head);
                    break;
           case 2: head=insert_end(head);
                    break;
           case 3: head=delete_front(head);
                    break;
           case 4: head=delete_end(head);
                    break;
           case 5: display(head);
                    break;
           case 6: exit(0);
                    break;
           default:printf("invalid");
       }

   }
}
