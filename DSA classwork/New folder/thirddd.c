#include<stdio.h>
#include<string.h>


typedef struct cricket_player
{
 char player_name[20];
char team_name[20];
float average;
int highest_score,centuries,j_no;
} PLR;


void read( PLR t[11])
{
 int i;
 printf("Enter player name Team name Average Highest score Centuries Jersey Number followed by space\n");
 for(i=0;i<5;i++)
 {
     scanf("%s %s %f %d %d%d",t[i].player_name,t[i].team_name,&t[i].average,&t[i].highest_score,&t[i].centuries,&t[i].j_no);
 }
}


void display( PLR t[11])
{
 int i;
 printf("\nPlayer Name\tteam Name\tAverage\t\tHigh Score\tCenturies\tJersey Number\n");
 for(i=0;i<4;i++)
 {
printf("%s\t\t%s\t\t%0.2f\t\t%d\t\t%d\t\t%d\n",t[i].player_name,t[i].team_name,t[i].average,t[i].highest_score,t[i].centuries,t[i].j_no);
 }
}


int highest_runs(PLR t[11])
{
 int i, h=0, index=0;
 for(i=0; i<5; i++)
 {
 if(t[i].highest_score>h)
 {
 h=t[i].highest_score;
 index=i;
 }
 }
 return index;
}


int lowest_runs(PLR t[11])
{
 int i, low=999, index=0;
 for(i=0; i<5; i++)
 {
 if(t[i].highest_score<low)
 {
 low=t[i].highest_score;
 index=i;
 }
 }
 return index;
}

int s_player(PLR t[11])
{
    int i,index,value;
    char str2[] = "Rajat";
    for(i=0;i<5;i++)
    {
        value=strcmp(t[i].player_name,str2);
           if(value==0)
            index=i;
    }
    return index;
}

void disp(PLR t[11],int index)
{
        int i=index;
        printf("%s\t\t%s\t\t%0.2f\t\t%d\t\t%d\t\t%d\n",t[i].player_name,t[i].t_name,t[i].average,t[i].highest_score,t[i].centuries,t[i].j_no);
}

int main( )
{
 int index,lindex,pind;
 PLR t[11];
 read(t);
 display(t);
 index=highest_runs(t);
 lindex=lowest_runs(t);
 pind=s_player(t);
 printf("Players Details selected are : \n");
 printf("\nPlayer Name\tTeam Name\tAverage\t\tHigh Score\tCenturies\tJersey Number\n");
 disp(t,index);
 disp(t,lindex);
 disp(t,pind);


}
