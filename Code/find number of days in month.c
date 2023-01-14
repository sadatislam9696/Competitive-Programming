#include<stdio.h>
int main()
{   while(1)
{
    int month;
    printf("Enter month number (1-12) :  ");
    scanf("%d",&month);

    if (month==1||month==3||month==5||month==7
            ||month==8||month==10||month==12)
    {
        printf("Month of days : 31\n ");
    }
    else if(month==4||month==6||month==9||month==11)
    {
        printf("Month of days : 30\n ");
    }
    else if (month==2)
    {
        printf("Month of days : 28/29\n ");
    }
    else
    {
        printf("Invalid input ! Enter month number\n");
    }
}
}
