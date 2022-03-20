void read(int a[])
{
    int i;
    printf("Enter the DSA score of 10 students:\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
}
int avg(int a[])
{
    int i,avg,sum=0;
    for(i=0;i<10;i++)
    {
        sum+=a[i];
    }
    avg=(float)(sum/10);
    return avg;
}
void count(int a[])
{
    int i,y,ab=0,be=0;
    y=avg(a);
    printf("Average = %d\n",y);
    for(i=0;i<10;i++)
    {
        if(a[i]<y)
            be++;
        else
            ab++;
    }
    printf("Number of students who scored above average = %d\n",ab);
    printf("Number of students who scored below average = %d\n",be);
}
void main()
{
    int a[10];
    read(a);
    count(a);
}
