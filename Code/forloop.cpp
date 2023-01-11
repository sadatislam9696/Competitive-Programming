#include<bits/stdc++.h>
using namespace std;
int main()
{
    //  for( int i=1       ;  i<=5    ;           i++        )
    //     (initialization )  (condition) (increment/decrement)


    for (int i=1; i<=5; i++)
    {
        cout<<"Bangladesh : "<<i<<endl;
    }

    for (int i=1; i<=5; i++)

    {
        cout<<i<<endl;
    }


    //////while loop


    int i = 1;                             //(initialization )
    while (i<=5)                          //(condition)
    {
        cout<<"Bangladesh : "<<i<<endl;
        i++;                               //increment/decrement
    }

    cout<<"End of while loop "<<endl;

    {
        int i = 5;                             //(initialization )
        while (i>=1)                          //(condition)
        {
            cout<<i<<endl;
            i--;                               //increment/decrement
        }
    }

    cout<<"End of while loop "<<endl;

    //////D0 while loop



    {

        int i=1;
        do
        {
            cout<<"Bangladesh : "<<i<<endl;
            i++;
        }
        while(i<=5);
    }

    {

        int i=5;
        do
        {
            cout<<i<<endl;
            i--;
        }
        while(i>=1);
    }

    cout<<"End of do while loop ";









}







