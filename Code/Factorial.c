#include<stdio.h>
int main()
{
    while (1)
    {
        int n,i,factorial = 1;
        printf("Enter any number : ");
        scanf("%d",&n);

        for (i=1; i<=n; i++)
        {
            factorial = factorial*i;
        }
        printf(" Factorial is : %d \n", factorial);
    }
}
