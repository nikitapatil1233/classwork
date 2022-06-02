#include<stdio.h>
typedef struct movies
{
    char movie[50];
    int date;
    float imbd,money;
}MV;
void read(FILE *fp, MV p[10], int n)
{
    int i;
    fp=fopen("producedmovies.txt","w");
    printf("\nEnter the NAME, RELEASE YEAR, iMDb RATING, COLLECTION OF MONEY IN CRORES\n");
    for (i=0;i<n;i++)
    {
        scanf("%s %d %f %f", p[i].movie, &p[i].date, &p[i].imbd, &p[i].money);
        fprintf(fp,"\n%s %d %f %f", p[i].movie, p[i].date, p[i].imbd, p[i].money);
    }
    fclose(fp);
}
void display(FILE *fp, MV p[10], int n)
{
    int i;
    fp=fopen("producedmovies.txt","r");
    printf("\nNAME\tRELEASE YEAR\tiMDb RATING\tCOLLECTION OF MONEY IN CRORES\n");

    {
        fscanf(fp,"\n%s %d %f %f", p[i].movie, &p[i].date, &p[i].imbd, &p[i].money);
        printf("%s\t%d\t\t%0.2f\t\t%0.2f\n",p[i].movie, p[i].date, p[i].imbd, p[i].money);
    }
    fclose(fp);
}
void total_collection(FILE *fp, MV p[10], int n)
{
    int i;
    float total=0;
    for(i=0;i<n;i++)
    {
        if(p[i].date == 2020)
        {
            total=total+p[i].money;
        }
    }
    printf("\nTOTAL COLLECTION IN CRORES IS: %0.2f\n\n", total);
}
int main()
{
    int n;
    printf("Enter the number of movies:");
    scanf("%d", &n);
    FILE *fp;
    MV p[10];
    read(fp,p,n);
    display(fp,p,n);
    total_collection(fp,p,n);
    return(0);
}
