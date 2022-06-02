#include<stdio.h>
struct complex_no
{
  int real;
  int imaginary;
};
struct complex_no read(struct complex_no z1)
{
printf("enter the real no ");
scanf("%d",&z1.real);
printf("\n enter the imaginary no");
scanf("%d",&z1.imaginary);
return z1;
}

struct complex_no add(struct complex_no z1, struct complex_no z2,  struct complex_no z3)
{
 z3.real=z1.real+z2.real;
 z3.imaginary=z1.imaginary+z2.imaginary;
 return z3;
}
void display(struct complex_no z3)
{
    printf("%d+i%d",z3.real,z3.imaginary);
}
int main()
{
struct complex_no z1,z2;
struct complex_no z3={0,0};
printf("enter the details of z1\n");
z1=read(z1);
printf("enter the details of z2\n");
z2=read(z2);
z3=add(z1,z2,z3);
printf("sum of two complex no z1 and z2 = \n");
display(z3);
}
