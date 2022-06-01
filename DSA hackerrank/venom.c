#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Venom
{
    char name[20];
    int age;
    struct Venom* next;
}*temp = NULL, *head = NULL;

typedef struct Venom *Queue;

Queue getNode()
{

    Queue newnode = (struct Venom*)malloc(sizeof(struct Venom));

    if (newnode == NULL)
    {
        printf("\nMemory not allocated");
        exit(0);
    }
    else
    {
        scanf("%s%d", newnode->name, &newnode->age);
        newnode->next = NULL;
        return newnode;
    }
}


int insert_rear(int j, int k)
{
    int i = 0, c = 0;

    for(int z = 0; z< j; z++)
    {
    Queue node = getNode();

    if(node->age <= 25 && node->age >= 18 && i <= k)
    {
    if (head == NULL)
    {

        head = node;
        temp = node;
        c++;
    }
    else
    {

        temp->next = node;
        temp = node;
        c++;
    }
    i++;
}

    }
    return c;
}

void display()
{

    Queue cur = head;
    do{
        printf("%s %d\n", cur->name, cur->age);
        cur = cur->next;
    }while(cur != NULL);

}

void search(char person[20])
{
    int f =1;
    Queue cur = head;
    do{
        if(strcmp(person, cur->name)==0)
        {
            printf("%d\n", f);
            return;
        }
        f++;
        cur = cur->next;
    }while(cur != NULL);
    printf("0\n");


}

int main()
{
    int n, k, out, bigline = 0, newline = 0;

    scanf("%d%d", &n, &k);
    if(n<=0)
    {
        printf("N should be greater than 0\n");
        exit(0);
    }
    out = insert_rear(n, k);
    char person[20];
    scanf("%s", person);
    display();
    search(person);
    bigline = 300*(n-out);
    newline = 300*out;
    printf("%d\n%d", bigline, newline);
}
