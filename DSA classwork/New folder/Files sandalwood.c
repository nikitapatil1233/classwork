#include<stdio.h>
#include<stdlib.h>
typedef struct movie
{
    char name[20];
    char producer[20];
    int date;
    int year;
    int collection;
}Mov;
void read(Mov *,int ,FILE *);
void gst(Mov *,int ,FILE *);
int main()
{
  Mov S[10];
  FILE *fp;
  int n,i;
  printf("Enter how many movie or serials details have to store\n");
  scanf("%d",&n);
  read(S,n,fp);
  gst(S,n,fp);
}
void read(Mov *p,int n,FILE *f)
{
    int i;
    f=fopen("producedmovies.txt","w");
    for(i=0;i<n;i++)
    {
        printf("Enter name of movie/serial, producer name, date and year of release, collection in box office for %d movie\n",(i+1));
        scanf("%s%s%d%d%d",p[i].name,p[i].producer,&p[i].date,&p[i].year,&p[i].collection);
        fprintf(f,"%s %s %d %d %d\n",p[i].name,p[i].producer,p[i].date,p[i].year,p[i].collection);
    }
    fclose(f);
    f=fopen("producedmovies.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %s %d %d %d\n",p[i].name,p[i].producer,&p[i].date,&p[i].year,&p[i].collection);
        printf("%s %s %d %d %d\n",p[i].name,p[i].producer,p[i].date,p[i].year,p[i].collection);
    }
    fclose(f);
}
void gst(Mov *p,int n,FILE *f)
{
    int i,sum=0;
    f=fopen("producedmovies.txt","r");
    for(i=0;i<n;i++)
    {
        fscanf(f,"%s %s %d %d %d\n",p[i].name,p[i].producer,&p[i].date,&p[i].year,&p[i].collection);
        if(p[i].year==2020)
        {
            sum=sum+p[i].collection;
        }
    }
    printf("Total collection is : %d\n",sum);
}
