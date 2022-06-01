#include <stdio.h>
#include <stdlib.h>

typedef struct dll
{
    int n;
    struct dll *next;
    struct dll *prev;
}  *NODE;
 NODE insert(NODE );
NODE getnode ();
 void select(NODE);


void  main()
{
    NODE head=NULL;
    int N;
    printf("Enter the number of Candidates:");
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        head=insert(head);
    }

    select(head);

    ;
}

NODE getnode ()
 {
     NODE newn;
     newn=(NODE) malloc(sizeof (struct dll));
     newn->next=NULL;
     newn->prev=NULL;
     scanf("%d",&newn->n);
     return newn;
 }
  NODE insert(NODE head)
 {
     NODE cur=head;
     NODE newn=getnode();
     if(head==NULL)
     return newn;
     while(cur->next!=NULL)
     {
         cur=cur->next;
     }
     cur->next=newn;
     newn->prev=cur;
     newn->next=NULL;
     return head;
 }

 void select(NODE head)
{
    NODE cur=head;
    int count=0;
    if(cur->n>150&&cur->n<cur->next->n)
    {
        count++;
        printf("%d  ",cur->n);
    }
    cur=cur->next;
    while(cur->next!=NULL)
    {
          if(cur->n>150&&cur->n<cur->next->n&&cur->n>cur->prev->n)
    {
        count++;
        printf("%d  ",cur->n);
    }
    cur=cur->next;
    }
     if(cur->n>150&&cur->n>cur->prev->n)
    {
        count++;
        printf("%d  ",cur->n);
    }
    printf("\n%d",count);

    }

