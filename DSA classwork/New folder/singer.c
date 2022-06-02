#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct music_list
{
char song_name[25];
int year;
char film_name[25];
int duration;
char singer[25];
struct music_list *next;
};




/* A user-defined data type called �NODE� */
typedef struct music_list *NODE;



NODE insert_front( NODE );
NODE insert_end(NODE);
void display_list(NODE);
NODE delete_end(NODE);
NODE delete_front(NODE);
NODE getNode();
void list_by_singer_Name(NODE head);
void highest_duration(head);
NODE delete_song_by_name(NODE head);
void main()
{
int choice;
NODE head=NULL;



while(1)
{
printf("\nPress\n 1 for insert song at end\n 2 for insert song front\n 3 for display songs\n 4 for Delete song at end \n5 for Delete song at front\n6 for search song\n7 for list by year\n8 Highest duration\n 9 for list by singer name\n10 Delete by song name\n11 for exit\n");
scanf("%d",&choice);



switch(choice)
{
case 1:head=insert_end(head);
break;
case 2:head=insert_front(head);
break;
case 3:display_list(head);
break;
case 4:head=delete_end(head);
break;
case 5:head=delete_front(head);
break;
case 6: search_song(head);
 break;
case 7: list_by_year(head);
 break;
case 8: highest_duration(head);
break;
case 9:list_by_singer_Name(head);
break;
case 10:head=delete_song_by_name(head);
break;
case 11:exit(0);
break;
default:printf("Invalid choice\n");
}
}
}



NODE getnode()
{
NODE newNode;
newNode=malloc(sizeof(struct music_list));
if(newNode==NULL)
{
printf("memory not allocated");
exit(0);
}
printf("enter song_name year film name duration singer name \n");
scanf("%s %d %s %d %s",newNode->song_name,&newNode->year,newNode->film_name,&newNode->duration,newNode->singer);
newNode->next=newNode;
return newNode;
}



NODE insert_end(NODE head)
{
NODE newNode,cur;
newNode=getnode();
if (head==NULL)
{
head=newNode;
return head;
}
else
{
cur=head;
while(cur->next!=head)



{
cur=cur->next;
}
cur->next=newNode;
newNode->next=head;
}
return head;
}
NODE insert_front( NODE head)
{
NODE newNode,cur;
newNode = getnode();
if(head == NULL)
{
head=newNode;
return head;
}
cur = head;
while (cur->next!= head)
{
cur = cur->next;
}
cur->next = newNode;
newNode->next=head;
head=newNode;
return head;
}



NODE delete_end(NODE head)
{
NODE prev, cur;
if(head==NULL)
{
printf("Song List Empty\n");
return head;
}
if(head->next==head)
{
printf("Deleted song: %s\n", head->song_name);
free(head);
head=NULL;
return head;
}
prev =NULL;
cur =head;
while(cur ->next != head)
{
prev= cur;
cur = cur ->next;
}
prev->next=head;
printf("Deleted song: %s\n", cur->song_name);
free(cur);
return head;
}
NODE delete_front(NODE head)
{
NODE cur,temp;
if(head==NULL)
{
printf("Song List Empty\n");
return head;
}
if(head->next==head)
{
printf("Deleted song : %s\n", head->song_name);
free(head);
head=NULL;
return head;
}
cur =head;
while(cur ->next != head)
{
cur = cur ->next;
}
temp=head;
head=head->next;
cur->next=head;
printf("Deleted song: %s\n", temp->song_name);
free(temp);
return head;
}
void highest_duration(NODE head)
{



if(head==NULL)
{
printf("List is empty\n");
}
else
{
NODE cur=head;
int High_dur=cur->duration;
cur=cur->next;
while(cur->next!=head)
{
if(cur->duration>High_dur)
High_dur=cur->duration;
cur=cur->next;
}
if(cur->duration>High_dur)
High_dur=cur->duration;
printf("highest duration %d\n",High_dur);
NODE temp=head;



while(temp->duration!=High_dur)
{
temp=temp->next;
}
printf("%s\t%d\t%s\t%d\t%s\n",temp->song_name,temp->year,temp->film_name,temp->duration,temp->singer);



}
}
void display_list(NODE head)
{
NODE cur;
if(head==NULL)
{
printf("Empty List\n");
return NULL;
}
printf("songs are\n");
cur = head;
printf("song_name year film_name Duration singer_name\n");
while (cur->next!=head)
{
printf("%s\t%d\t%s\t%d\t%s\n",cur->song_name,cur->year,cur->film_name,cur->duration,cur->singer);
cur = cur->next;
}
printf("%s\t%d\t%s\t%d\t%s\n",cur->song_name,cur->year,cur->film_name,cur->duration,cur->singer);
}
void list_by_singer_Name(NODE head)
{
char sname[20];
printf("Enter the name\n");
scanf("%s",sname);
NODE cur;
if(head==NULL)
{
printf("Empty List\n");
return NULL;
}
cur = head;
int flag=0;
while (cur->next!=head)
{
if(strcmp(cur->singer,sname)==0)
{
flag=1;
printf("%s\t%d\t%s\t%d\t%s\n",cur->song_name,cur->year,cur->film_name,cur->duration,cur->singer);



}
cur = cur->next;
}
if(strcmp(cur->singer,sname)==0)
{
flag=1;
printf("%s\t%d\t%s\t%d\t%s\n",cur->song_name,cur->year,cur->film_name,cur->duration,cur->singer);



}
if(flag==0)
{
printf("no songs in the singer name %s \n",sname);
}
}

void search_song(NODE head)

{
     char songname[20];
 printf("Enter the name\n");
 scanf("%s",songname);
 NODE cur;
 if(head==NULL)
 {
 printf("Empty List\n");
 return NULL;
 }
 cur = head;
 int flag=0;
 printf("Song Name\tSinger Name\tMovieName\tYear\tDuration \n");
 while (cur->next!=head)
 {
 if(strcmp(cur->song_name,songname)==0)
 {
 flag=1;
 printf("%s\t\t%s\t\t%s\t\t%d\t\t%d\n",cur->song_name,cur->singer,cur->film_name,cur->year,cur->duration);
 }
 cur = cur->next;
 }
if(strcmp(cur->song_name,songname)==0)
 {
  flag=1;
  printf("%s\t\t%s\t\t%s\t\t%d\t\t%d\n",cur->song_name,cur->singer,cur->film_name,cur->year,cur->duration);
 }
if(flag==0)
 {
 printf("Song does not exist\n");
 }
}
void list_by_year(NODE head)
{
int yr[20];
printf("Enter the year\n");
scanf("%d",yr);
NODE cur;
if(head==NULL)
{
printf("Empty List\n");
return NULL;
}
cur = head;
int flag=0;
while (cur->next!=head)
{
if(strcmp(cur->year,yr)==0)
{
flag=1;
printf("%s\t%d\t%s\t%d\t%s\n",cur->song_name,cur->year,cur->film_name,cur->duration,cur->singer);



}
cur = cur->next;
}
if(strcmp(cur->year,yr)==0)
{
flag=1;
printf("%s\t%d\t%s\t%d\t%s\n",cur->song_name,cur->year,cur->film_name,cur->duration,cur->singer);



}
if(flag==0)
{
printf("no songs in the year %d \n",yr);
}
}


NODE delete_song_by_name(NODE head)
{
char ssname[20];
int flag=0;
printf("Enter the song name\n");
scanf("%s",ssname);
NODE prev=NULL, cur=head;
if(head==NULL)
{
printf("Song List Empty\n");
return head;
}
if(head->next==head)
{
if(strcmp(head->song_name,ssname)==0)
{
flag=1;
printf("Deleted song: %s\n", head->song_name);
free(head);
head=NULL;
}



}
prev =NULL;
cur =head;
while(cur ->next != head)
{
if(strcmp(cur->song_name,ssname)==0)
{
flag=1;
prev->next=cur->next;
printf("Deleted song: %s\n", cur->song_name);
free(cur);



break;
}
prev= cur;
cur = cur ->next;
}
if(cur->next==head)
{
if(strcmp(cur->song_name,ssname)==0)
{
flag=1;
prev->next=head;
printf("Deleted song: %s\n", cur->song_name);
free(cur);
}
}



if(flag==0)
{
printf("Song is not the list to delete\n");
}



return head;
}
