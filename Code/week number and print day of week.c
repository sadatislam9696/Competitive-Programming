#include<stdio.h>
int main()
{   while(1)
    {
    int week;
    printf("Enter week number (1-7) : ");
    scanf("%d",&week);

    if (week==1)
    {
        printf("SAT\n");
    }
    else if(week==2)
    {
        printf("SUN\n");
    }
    else if(week==3)
    {
        printf("MUN\n");
    }
    else if(week==4)
    {
        printf("TUE\n");
    }
    else if(week==5)
    {
        printf("WED\n");
    }
    else if(week==6)
    {
        printf("THU\n");
    }
    else if(week==7)
    {
        printf("FRI\n");
    }
    else
    {
        printf("No week day\n");
    }
    }

}
