#include<stdio.h>
int main()
{
   /* input   123 456 789
    output  654
            123456
            987
            123456789*/
    int num1,num2,num3,reverce=0,reminder;
    printf("Enter three number : ");
    scanf("%d%d%d",&num1,&num2,&num3);

    ////reverce num2
    while(num2!=0)
    {
        reminder=num2%10;
        reverce=reverce*10+reminder;
        num2=num2/10;

    }
    printf("%d\n",reverce);

    int reverce1=num1;
    int newnumber = reverce ;
    while(newnumber!=0)
    {
        int reminder1=newnumber%10;
        reverce1=reverce1*10+reminder1;
        newnumber=newnumber/10;

    }
    printf("%d\n",reverce1);


////reverce num3
    int reverce3=0,reminder3;
    while(num3!=0)
    {
        reminder3=num3%10;
        reverce3=reverce3*10+reminder3;
        num3=num3/10;

    }
    printf("%d\n",reverce3);

    int reverce4=reverce1;
    int newnumber1=reverce3;
    while(newnumber1!=0)
    {
        int reminder4=newnumber1%10;
        reverce4=reverce4*10+reminder4;
        newnumber1=newnumber1/10;

    }
    printf("%d\n",reverce4);



}

