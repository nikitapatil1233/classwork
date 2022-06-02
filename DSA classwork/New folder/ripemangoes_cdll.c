#include<stdio.h>
#include<stdlib.h>

struct mango
{
    int ripe;
    struct mango *next, *prev;
};
typedef struct mango *NODE;

//function prototypes.
NODE getnewnode();
NODE insert_end_cdll(NODE head);
NODE delete_front_cdll(NODE head);
void display_cdll(NODE head);
void falling_mangoes(NODE head);

int main()
{
    int i , n;
    NODE head=NULL;
    printf("Enter number of mangoes\n");
    scanf("%d", &n);
    for(i=0;i<n;i++)
        head= insert_end_cdll(head);
    display_cdll(head);

    falling_mangoes(head);
    return 0;
}

NODE getnewnode()
{
    NODE newn = (NODE)malloc(sizeof(struct mango));
    if(newn == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        printf("Enter ripe level of mango\n");
        scanf("%d", &newn->ripe);
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

void display_cdll(NODE head)
{
    NODE cur=head;
    if(head==NULL)
        printf("CDLL of mangoes is empty\n");
    else
    {
        do
        {
            printf("%d ", cur->ripe);
            cur = cur->next;
        }while(cur != head);
    }
}

NODE delete_front_cdll(NODE head)
{
    NODE del=NULL, cur=NULL;
    if(head==NULL)
        printf("CDLL of mangoes is empty\n");
    else
    {
        cur = head->prev;
        del = head;
        head = head->next;

        cur->next = head;
        head->prev = cur;
        printf("\nDeleting mango with ripe level %d\n", del->ripe);
        free(del);
    }
    return head;
}

void falling_mangoes(NODE head)
{
    NODE tail=NULL,cur=NULL;
    int count=0,c=0;
    if(head==NULL)
    {

        printf("CDLL of mangoes is empty\n");

    }
    else
    {
        tail = head->prev;
        while(head != tail)
        {

            if(head->ripe > head->next->ripe)
            {
                    head = delete_front_cdll(head);
                    count++;
            }
            else
            {
                head = head->next;
            }
        }

        if(head->ripe > head->next->ripe)
        {
            head= delete_front_cdll(head);
            count++;
        }
        else
        {
            head = head->next;
        }
    }
    cur=head;

        do
        {
            c++;
            cur=cur->next;
        }
        while(cur!=head);

    printf("\nRemaining mangoes\n");
    display_cdll(head);
    printf("\nMangoes fallen from tree = %d\n", count);
    printf("\nMangoes on the tree = %d\n", c);
}
