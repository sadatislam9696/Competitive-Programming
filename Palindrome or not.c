#include<stdio.h>
int main()
{   //kono 1ti number ke jodi (121) reverse korle
    //abar ei number ti ashe (121) tahole sei number ti
    //palindrome hobe...
    while (1)
    {
        int num, temp, rem, sum = 0;
        printf("Enter any number : ");
        scanf("%d",&num);

        temp = num;
        while (temp!=0)
        {
            rem = temp % 10;
            sum = sum * 10 + rem;
            temp = temp/10;
        }
        if (num==sum)
            printf("It is palindrome\n");
        else
            printf("I is not palindrome\n");
    }
}
