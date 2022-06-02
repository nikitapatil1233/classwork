#include<stdio.h>
#include<stdlib.h>

struct loot
{
    int house_number;
    int money;
    struct node *next ;
};

typedef struct loot NODE ;

NODE * create_node(NODE *new)
{
    new = (NODE *)malloc(sizeof(NODE));
    scanf("%d",&new->house_number);
    scanf("%d",&new->money);
    new->next = new;
    return new;
}

NODE *append(NODE *head)
{
    NODE *new = create_node(new);

    if(head == NULL)
    {
        head = new;
        return head;
    }

    if(head -> next  == head)
    {
        head -> next =new;
        new-> next = head;
        return head ;
    }
    NODE *curr = head ;
    while(curr->next != head)
    {
        curr =  curr->next;
    }
    curr -> next = new;
    new-> next = head ;
    return  head;
}

void looting_first_and_last_house(NODE *head)
{
    int looted_money = 0;
    NODE *curr = head ;

    while(curr -> next != head)
    {
        if(curr == head)
        {
            looted_money += curr->money;
        }
        curr = curr->next;
    }
    looted_money += curr ->money;
    printf("Total loot = %d",looted_money);

}

void print_non_looted_house(NODE *head)
{
    NODE * curr = head -> next;
    while(curr ->next != head)
    {
        printf("%d ",curr->house_number);
        printf("%d\n",curr->money);
        curr = curr->next;
    }
}

int main()
{
    NODE *head  = NULL;
    int n;
    scanf("%d",&n);
    if(n<5)
    {
        printf("Kaalia cannot loot the houses");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        head = append(head);
    }
    print_non_looted_house(head);
    looting_first_last_house(head);
    return 0;
}
