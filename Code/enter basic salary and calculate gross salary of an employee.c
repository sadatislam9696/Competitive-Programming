#include<stdio.h>
int main()
{
    float basic,hra,da,gross;
    printf("Enter basic salary of an employee : ");
    scanf("%f",&basic);
    //  Basic Salary <= 10000 : HRA = 20%, DA = 80%
    //  Basic Salary <= 20000 : HRA = 25%, DA = 90%
    //  Basic Salary > 20000 : HRA = 30%, DA = 95%

    if (basic<=10000)
    {
        hra = basic*0.2;
        da = basic*0.8;
    }
    else if (basic<=20000)
    {
        hra = basic*0.25;
        da = basic*0.9;
    }
    else
    {
        hra = basic*0.3;
        da = basic*0.95;
    }
    gross = basic + hra + da;
    printf("GROSS SALARY OF EMPLOYE = %.2f",gross);

}
