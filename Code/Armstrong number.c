#include<stdio.h>
int main()
{

int num,temp,rem,sum=0;
printf("Enter any digit : ");
scanf("%d",&num);
temp=num;

while (temp!=0)
{
    rem=temp%10;
    sum=sum+rem*rem*rem ;
    temp=temp/10;
}
if (num==sum)
{
    printf("Armstrong number\n");
}
else
{
    printf("Not Armstrong number\n");

}
/////////check Armstrong number 1 to 1000

{
    int initialnum,finalnum,temp,rem,sum=0,i;
    printf("Enter initial value : ");
    scanf("%d",&initialnum);

    printf("Enter final value :");
    scanf("%d",&finalnum);

    for(i=initialnum; i<=finalnum; i++)


    {
        temp=i;

        while (temp!=0)
        {
            rem=temp%10;
            sum=sum+rem*rem*rem ;
            temp=temp/10;
        }
        if (sum==i)
        {
            printf("%d\n",i);
        }
        sum=0;
    }
}
}

