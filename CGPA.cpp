#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct student
{
    int roll;
    char name[20],lastna[20];
    int ar[5];
    float gpa;
}st[44],temp;
void calgpa()
{
    system("COLOR F0");
    FILE *ft,*yu;
    char name[20],lastna[20];
    float gpa;
    int roll,ar[5];
    int i;
    ft=fopen("file.txt","r");
    yu=fopen("temp.txt","w");
    for(i=1;i<=44;i++)
    {
        fscanf(ft," %d %s %s %d %d %d %d %d", &roll,&name,&lastna,&ar[0],&ar[1],&ar[2],&ar[3],&ar[4]);
        gpa=(float)((4*(ar[0]+ar[4])/2)+3*ar[3]+2*ar[2]+ar[1])/14;
        fprintf(yu," %d %s %s %d %d %d %d %d %0.1f\n", roll,name,lastna ,ar[0],ar[1],ar[2],ar[3],ar[4],gpa);
        //printf(" %d %s %s %d %d %d %d %d", roll,name,lastna ,ar[0],ar[1],ar[2],ar[3],ar[4]);
        //printf("\n");
    }
    printf("\n\n\n\n\n\n\n\t\t\t\t\tWAIT UNTIL CGPA IS CALCULATED\n");
    fclose(ft);
    fclose(yu);
}
void selectionsort()
{
    system("COLOR 1f");
    system("cls");
    int i,j,pos;
    FILE *fp,*fo;
    fp=fopen("temp.txt","r");
    fo=fopen("sorted.txt","w");
    for(i=1;i<=44;i++)
    {
        fscanf(fp," %d %s %s %d %d %d %d %d %f", &st[i].roll,&st[i].name,&st[i].lastna,&st[i].ar[0],&st[i].ar[1],&st[i].ar[2],&st[i].ar[3],&st[i].ar[4],&st[i].gpa);
    }
    float small;
    for(i=1;i<44;i++)
    {
        small=st[i].gpa;
        pos=i;
        j=i+1;
        while(j<44)
        {
            if(small>st[j].gpa)
            {
                small=st[j].gpa;
                pos=j;
            }
            j=j+1;
        }
        temp=st[i];
        st[i]=st[pos];
        st[pos]=temp;
    }
    for(i=1;i<=44;i++)
    {
        fprintf(fo," %d %s %s %d %d %d %d %d   %0.1f\n", st[i].roll,st[i].name,st[i].lastna,st[i].ar[0],st[i].ar[1],st[i].ar[2],st[i].ar[3],st[i].ar[4],st[i].gpa);
    }
    fclose(fo);
    fclose(fp);
    printf("\n\n\n\n\n\n\n\t\t\t\t\tWAIT FILE IS BEING SORTED\n");
}
void display()
{
    system("cls");
    int i,roll;
    int ar[5];
    char name[20],lastna[20];
    float gpa;
    FILE *fp;
    fp=fopen("sorted.txt","r");
    for(i=1;i<=44;i++)
    {
        fscanf(fp," %d %s %s %d %d %d %d %d  %0.1f", &st[i].roll,&st[i].name,&st[i].lastna,&st[i].ar[0],&ar[1],&st[i].ar[2],&st[i].ar[3],&st[i].ar[4],&st[i].gpa);
        printf(" %d %s %s %d %d %d %d %d   %0.1f", st[i].roll,st[i].name,st[i].lastna ,st[i].ar[0],st[i].ar[1],st[i].ar[2],st[i].ar[3],st[i].ar[4],st[i].gpa);
        printf("\n");
    }
    fclose(fp);
}
main()
{
    calgpa();
    printf("\n\n\n\n\n\n\n\t\t\t\t\tPRESS ANY KEY\n");
    getch();
    selectionsort();
    printf("\n\n\n\n\n\n\n\t\t\t\t\tPRESS ANY KEY\n");
    getch();
    printf("PRESS ANY KEY ");
    display();
}
