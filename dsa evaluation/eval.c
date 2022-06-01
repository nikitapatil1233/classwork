#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
   int val;
   struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE newn;
    int data;
    newn=(NODE)malloc(sizeof(struct node));
    if(newn==NULL)
    {
        printf("Not created\n");
        exit(0);
    }
    printf("enter height\n");
    scanf("%d",&data);
    newn->val=data;
    newn->next = NULL;
    return newn;
}

NODE insert_end (NODE head)
{
    NODE new, temp;
    new = getnode();
    new ->next = NULL;
            if(head==NULL)
              return new;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp-> next = new;
    new->next = NULL;
        return head;
}
NODE select(NODE head)
{
    NODE temp1,temp2;
    int count=0;
    temp1=head;
    if (temp1->val>=150 && temp1->val<temp1->next->val)
    {
         display(temp1);
        count = count+1;
    }
    temp2=temp1->next;
    while (temp2->next!=NULL)
    {
        if (temp2->val>=150 && temp2->val<temp2->next->val && temp2->val>temp1->val)
        {
        display(temp2);
        count = count+1;
        temp2=temp2->next;
        temp1=temp1->next;
        }
        else

        temp2=temp2->next;
        temp1->next=temp2;
    }
    if (temp2->val>=150 && temp2->val>temp1->val)
    {
        display(temp1);
        count = count+1;
    }
    printf("\n%d",count);
    return head;

}
void display(NODE first)

{
      NODE n;
      n=first;
      printf("%d\t",n->val);
}



int main()
{
   NODE head=NULL;
   int N,i;
   printf("enter number of candidates");
   scanf("%d", &N);
   for ( i = 0; i < N; i++)
   {
       head=insert_end(head);
   }
   head=select(head);
   return 0;
}
