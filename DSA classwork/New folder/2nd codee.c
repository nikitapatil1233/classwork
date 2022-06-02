#include<stdio.h>
#include<math.h>

typedef struct points
{


  float x;
  float y;
}POINTS;
void read(POINTS*p1, POINTS*p2)
{


    printf("The coordinates of x and y for point p1 is \n");
    scanf("%f%f", &p1->x, &p1->y);
    printf("Enter the values of x and y for point p2 is n");
    scanf("%f%f", &p2->x, &p2->y);
}
void quadrant(POINTS*p1, POINTS*p2)
{
    printf("\n\n");
    if(p1->x>0&&p1->y>0)
        printf("Point 1 lie in 1st quadrant\n");
    else if(p1->x>0&&p1->y<0)
        printf("Point 1 lie in 4th quadrant\n");
    else if(p1->x<0&&p1->y>0)
        printf("Point 1 lie in 2nd quadrant\n");
    else if(p1->x<0&&p1->y<0)
        printf("Point 1 lie in 3rd quadrant\n");
         if(p2->x>0&&p2->y>0)
        printf("Point 2 lie in 1st quadrant\n");
    else if(p2->x>0&&p2->y<0)
        printf("Point 2 lie in 4th quadrant\n");
    else if(p2->x<0&&p2->y>0)
        printf("Point 2 lie in 2nd quadrant\n");
    else if(p2->x<0&&p2->y<0)
        printf("Point 2 lie in 3rd quadrant\n");
}
void distance(POINTS*p1,POINTS*p2)
{
    float d;
    d=sqrt((pow((p2->x-p1->x),2))+pow((p2->y-p1->y),2));
    printf("\n\nDistance between two points %0.2f\n",d);
}
void slope(POINTS*p1, POINTS*p2)
{
    float m;
    m=(p2->y-p1->y)/(p2->x-p1->x);
    printf("\n\nSlope between two points %0.2f\n",m);
}

printf("The coordinates of the point p1 are: ");
scanf("%f%f",&p1->x,&p2->y);

printf("\nThe coordinates of the point p2 are: ");
scanf("%f%f",&p1->x,&p2->y);

d = sqrt((p1->x - p2->x)*(p1->x - p2->x) + (p1->y - p2->y)*(p1->y - p2->y));
printf("\nThe distance between p1 and p2 is %f\n",d);

}
int main()
{
    POINTS p,q;
    POINTS*p1;
   POINTS*p2;
    p2=&q;
    p1=&p;
    read(p1, p2);

    quadrant(p1, p2);
    distance(p1,p2);
    slope(p1,p2);
}
