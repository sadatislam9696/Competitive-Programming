#include<bits/stdc++.h>
using namespace std;
int main()
{
    {
        //////Large number
        int num1, num2 ;
        num1 = 20;
        num2 = 25;
        int max = (num1>num2)? num1 : num2;
        cout<<"Large number is  : "<<max<<endl;
    }

    {
        ////Even odd
        int num;
        cout<<"Enter any integer : ";
        cin>>num;

        int (num%2==0) ? cout<<num <<" is even" <<endl : cout<<num <<" is odd" <<endl ;
    }

    {
        ////pass fail
        int num;
        cout<<"Enter any integer : ";
        cin>>num;
        int (num>=33)?cout<<"Your number is : "<<num<<" you pass" : cout<<"Your number is : "<<num<<" you Fail";

    }






}
