#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
 int x,y,z,i,num;
 scanf("%d",&num);
if(num>0&&num<=40)
{
 x=2;
 y=1;
 for(i=0;i<num;i++)
 {
   printf("%d ",x);
   z=x+y;
   x=y;
   y=z;
 }
}
 else
     printf("Invalid input");
 return 0;
}
