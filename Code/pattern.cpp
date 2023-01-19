#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num,row,col;
    cout<<"Enter number of lines : ";
    cin>>num;

    for(row=1;row<=num;row++)
    {
        for(col=1;col<=row;col++)
        {
            cout<<" * " ;
        }
        cout<<endl;
    }
}
