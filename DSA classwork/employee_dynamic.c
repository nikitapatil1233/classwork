
#include <stdio.h>
#include <stdlib.h>
struct employee
{
    int id;
    char name[50];
};
typedef struct employee e1;
void read(struct employee *ptr, int n);
void display(struct employee *ptr, int n);

int main()
{
    int n;
    struct employee *ptr;
    printf("Enter total number of employees :");
    scanf("%d", &n);
    ptr = (struct employee *)malloc(sizeof(struct employee) * n);
    read(ptr, n);
    display(ptr, n);
    free(ptr);

    return 0;
}
void read(struct employee *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d employee details:", i + 1);
        scanf("%d%s", &(ptr + i)->id, &(ptr + i)->name);
    }
}
void display(struct employee *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d Employee Id : %d\n", i + 1, (ptr + i)->id);
        printf(" %d Employee Name :%s\n", i + 1, (ptr + i)->name);
    }
}
