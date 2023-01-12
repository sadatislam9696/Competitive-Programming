#include<stdio.h>
int main()
{///////same sum of digit
    int num,temp,rem,sum = 0;
    //temporary,reminder
    printf("Enter any digits : ");
    scanf("%d",&num);

    temp = num;
    while(temp!=0)
    {
        rem = temp % 10;
        sum = sum * 10 + rem;
        temp = temp / 10;

    }
    printf("Reverse of number : %d\n ",sum );
}
