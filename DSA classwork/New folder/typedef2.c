#include<stdio.h>
typedef struct date
{
    int date ,year;
    char month[100];
}DAT;
typedef struct smart_phone
{
    char name[10], model[20];
    DAT dte;
    int ram,rom;
    float price;
}SP;
void read(FILE *fp, SP p[10], int n)
{
    int i;
    fp=fopen("smartphone.txt","w");
    printf("\n\nEnter the NAME, MODEL, DATE OF LAUNCH, RAM, ROM, PRICE of the smart phones\n");
    for (i=0;i<n;i++)
    {
        scanf("%s%s%d%s%d%d%d%f", p[i].name, p[i].model, &p[i].dte.date, p[i].dte.month, &p[i].dte.year, &p[i].ram, &p[i].rom, &p[i].price);
        fprintf(fp,"\n%s %s %d %s %d %d %d %0.2f", p[i].name, p[i].model, p[i].dte.date, p[i].dte.month,p[i].dte.year, p[i].ram, p[i].rom, p[i].price );
    }
    fclose(fp);
}
void display(FILE *fp, SP p[10], int n)
{
    int i;
    fp=fopen("smartphone.txt","r");
    printf("\nNAME\tMODEL\tDATE OF LAUNCH\t\tRAM\t\tROM\tPRICE\n");

    {
        fscanf(fp,"\n%s %s %d %s %d %d %d %f", p[i].name, p[i].model, &p[i].dte.date, p[i].dte.month, &p[i].dte.year, &p[i].ram, &p[i].rom, &p[i].price);
        printf("%s\t%s\t%d %s %d\t\t%d\t%d\t%0.2f\n", p[i].name, p[i].model, p[i].dte.date, p[i].dte.month,p[i].dte.year, p[i].ram, p[i].rom, p[i].price );
    }
    fclose(fp);
}
void least(FILE *fp, SP p[10], int n)
{
    int i=0, index=0;
    int mini=999999999;
    printf("\nMOBILE WITH LEAST COST\n");
    fp=fopen("smartphone.txt","r");

    {
        fscanf(fp,"\n%s %s %d %s %d %d %d %f", p[i].name, p[i].model, &p[i].dte.date, p[i].dte.month, &p[i].dte.year, &p[i].ram, &p[i].rom, &p[i].price);
        if(mini>p[i].price)
        {
            mini=p[i].price;
            index=i;
        }
        i++;
    }
    printf("\n\n%s\t%s\t%d %s %d\t%d\t%d\t%0.2f\n", p[index].name, p[index].model, p[index].dte.date, p[index].dte.month,p[index].dte.year, p[index].ram, p[index].rom, p[index].price );
}

void latest(FILE *fp, SP p[10], int n)
{
    int i=0, index=0;
    int max=0;
    printf("\nMOBILE LAUNCHED RECENTLY\n");
    fp=fopen("smartphone.txt","r");

    {
        fscanf(fp,"\n%s %s %d %s %d %d %d %f", p[i].name, p[i].model, &p[i].dte.date, p[i].dte.month, &p[i].dte.year, &p[i].ram, &p[i].rom, &p[i].price);
        if(max<(p[i].dte.date+p[i].dte.year))
        {
            max=p[i].dte.date+p[i].dte.year;
            index=i;
        }
        i++;
    }
    printf("\n\n%s\t%s\t%d %s %d\t%d\t%d\t%0.2f\n", p[index].name, p[index].model, p[index].dte.date, p[index].dte.month,p[index].dte.year, p[index].ram, p[index].rom, p[index].price );

}
int main()
{
    int n;
    printf("Enter the number of smart phone:");
    scanf("%d", &n);
    FILE *fp;
    SP p[10];
    read(fp,p,n);
    display(fp,p,n);
    least(fp,p,n);
    latest(fp,p,n);
    return(0);
}
