#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

struct q
{
    char vnum[SIZE][15];
    char vtype[SIZE][5];
    int cost[SIZE];
    int front;
    int rear;
};
typedef struct q QUEUE;

QUEUE create_queue()
{
    QUEUE q1;
    q1.front = -1;
    q1.rear = 0;
    return q1;
}

void enqueue(QUEUE *q1)
{
    char vcnum[15], vctype[5];
    if(q1->rear == SIZE)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter vehicle number, vehicle type (as LMV or HMV)\n");
        scanf("%s%s", vcnum, vctype);
        strcpy(q1->vnum[q1->rear],vcnum);
        strcpy(q1->vtype[q1->rear], vctype);
        if(strcmp(q1->vtype[q1->rear],"HMV")==0)
            q1->cost[q1->rear]= 100;
        else
            q1->cost[q1->rear]= 50;
        q1->rear ++;
    }
}

void dequeue(QUEUE *q1)
{
    if(q1->rear == q1->front +1)
        printf("Queue Underflow\n");
    else
    {
        q1->front++;
        printf("\nVehicle moving out of toll: %s. %s. \n", q1->vnum[q1->front], q1->vtype);
    }
}


void displayqueue(QUEUE *q1)
{
    int i;
    if(q1->rear == q1->front+1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Vehicles at Toll bay are: \n");
        for(i=q1->front+1; i<q1->rear; i++)
        {
                printf("%s %s %d\n", q1->vnum[i], q1->vtype[i], q1->cost[i]);
        }
        printf("\n");
    }
}

void displayqueuevehicles(QUEUE *q1)
{
    int i, lmvcount=0;
    if(q1->rear == q1->front+1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("HMV Vehicles at Toll bay are: \n");
        for(i=q1->front+1; i<q1->rear; i++)
        {
            if(strcmp(q1->vtype[i], "HMV")==0)
                printf("%s %s %d\n", q1->vnum[i], q1->vtype[i], q1->cost[i]);
            else
                lmvcount++;
        }
        printf("\n");
    }
    printf("Number of LMV vehicles waiting to pass toll are: %d\n", lmvcount);
}
