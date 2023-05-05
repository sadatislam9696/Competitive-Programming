#include<stdio.h>
int main()
{
    char ch;
    printf("Enter any charecter : ");
    scanf("%c",&ch);

    if ((ch>='a'&&ch<='z')||(ch>= 'A'&&ch<='Z'))
    {
        printf(" It is alphabet\n",ch);

    }
    else
    {
        printf(" It is not alphavet",ch);
    }
}
