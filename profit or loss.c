#include<stdio.h>
int main()
{
    int cost,sell,profit,loss;

    printf("Cost price : ");
    scanf("%d",&cost);
    printf("selling price : ");
    scanf("%d",&sell);

    if (sell>cost)
    {
        profit = sell-cost;
        printf("Profit = %d\n",profit);
    }
    else if (cost>sell)
    {
        loss = sell - cost;
        printf("Loss = %d\n",loss);
    }
}
