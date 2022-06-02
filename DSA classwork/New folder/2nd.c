#include<stdio.h>
typedef struct store_books
{
    char name[100],subject_related[100];
    int ISBN_number;
}SB;
void read(SB b[100], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("Enter the NAME\t SUBJECT\t ISBN NUMBER of book %d\n", i+1);
        scanf("%s%s%d", b[i].name, b[i].subject_related, &b[i].ISBN_number);
    }
}
void display(SB b[100], int n)
{
 int i;
    for (i=0;i<n;i++)
    {
        printf("NAME\t SUBJECT\t ISBN NUMBER\n", i+1);
        printf("%s\t%s\t\t%d\n", b[i].name, b[i].subject_related, b[i].ISBN_number);
    }
}
void sort(SB b[100], int n)
{
    int i, j,a;
    for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (b[i].ISBN_number > b[j].ISBN_number )
                {
                    a =  b[i].ISBN_number;
                    b[i].ISBN_number =  b[j].ISBN_number;
                    b[j].ISBN_number = a;
                }

            }
        }
         printf("The books arranged in ascending order of ISBN are given below \n");
        for (i = 0; i < n; i++)
        {
            printf("NAME\t SUBJECT\t IBSN NUMBER\n");
            printf("%s\t%s\t\t%d\n", b[i].name, b[i].subject_related, b[i].ISBN_number);
        }
}
void search(SB b[100], int n)
{
    int i, p;
    printf("Enter the ISBN number you want to search:");
    scanf("%d", &p);
    for (i=0;i<n;i++)
    {
        if(p==b[i].ISBN_number)
        {
            printf("NAME\t SUBJECT\t ISBN NUMBER\n");
            printf("%s\t%s\t\t%d\n", b[i].name, b[i].subject_related, b[i].ISBN_number);
        }
    }
}
int main()
{
    int n;
    SB b[100];
    printf("Enter the number of books:");
    scanf("%d", &n);
    read(b,n);
    display(b,n);
    sort(b,n);
    search(b,n);
    return 0;
}
