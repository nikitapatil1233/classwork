#include<stdio.h>
void area(float *a,float r)
{
    *a=3.14*r*r;
}
int main()
{
    float a,r;
    printf("Enter radius:\n");
    scanf("%f",&r);
    area(&a,r);
    printf("Area of circle with radius %.1f : %.2f ",r,a);
    return 0;
}
