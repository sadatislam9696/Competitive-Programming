#include<stdio.h>
int main()
{
    int che,phy,com,bio,math;
    float per;

    printf("Enter five subject of marks : ");
    scanf("%d%d%d%d%d",&che,&phy,&com,&bio,&math);

    per = (che + phy + com + bio + math)/5;
    printf("Percentage = %f\n",per);

    if (per>=90)
    {
        printf("Grade = A");
    }
    else if (per>=80)
    {
        printf("Grade = B");
    }

    else if (per>=70)
    {
        printf("Grade = C");
    }

    else if (per>=60)
    {
        printf("Grade = D");
    }


    else if (per>=50)
    {
        printf("Grade = D");
    }


    else if (per>=40)
    {
        printf("Grade = E");
    }
    else

   {
       printf("Grade = F");
   }


}











