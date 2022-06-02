# include <stdio.h>
#include <stdlib.h>

#include <string.h>


struct subject
{
char name [25];

struct subject*next;
};

typedef struct subject*NODE;

int Acount = 0;

int Pcount=0;
int Gcount = 0;



NODE getnode ()
{

NODE newn

newn=(NODE) malloc (size of (struct subject))

if (newn== NULL)
{
printf ("Memory not allocated \n");
}
else
{

scanf ("%s",newn->name);
 newn-> next = NULL;
}
return newn;
}

NODE push (NODE list_sub)
{

NODE newn = get node ();
 if (list_sub == NULL)
{
    list_sub=newn;
}
else
{
    newn->next=list_sub;
    list_sub=newn;
}
return list_sub;
}


void display (NODE list_sub)
{
NODE cur;
cur=list_sub;
if (list_sub==NULL)
{
    printf("no names in stack");

}
else
{
    while(cur!=NULL)
    {

        if(strcmp(cur->name,"Astronomic")==0)
    {
        printf("%s\n",cur->name);
        Acount++;
        cur=cur->next;
    }
    else
    {
        cur=cur->next;
    }
    }
    cur=list_sub;
    while(cur!=NULL)
    {
        if(strcmp(cur->name,"Physics")==0)
    {
        printf("%s\n",cur->name);
        Pcount++;
        cur=cur->next;
    }
    else
    {
        cur=cur->next;
    }
    }
     cur=list_sub;
    while(cur!=NULL)
    {
        if(strcmp(cur->name,"Geography")==0)
    {
        printf("%s\n",cur->name);
        Gcount++;
        cur=cur->next;
    }
    else
    {
        cur=cur->next;
    }
    }

    if(Acount==0)
    {
        printf("%d%d",Pcount,count);
    }
    else if(Pcount==0)
    {
        printf("%d%d",Acount,count);
    }
    else if(count==0)
    {
        printf("%d%d",count,Pcount);
    }
    else
    {
        printf("%d%d",Acount,Pcount,Gcount);
    }
}

}
int main()
{
    int i,n,s;
    NODE subject=NULL;
    scanf("%d",&n);
    if (n<=0)
    {
        printf("Number of books or subjects should be positive \n");

    }
    else
    {
        scanf("%d",&s);
        if (s<=0)
        {
            printf("Number of books or subjects should be positive\n");
        }
        else
        {
            for(i=0;i<n;i++)
            {
                subject=push(subject);
            }
            display(subject);
        }
        return 0;
    }
}
