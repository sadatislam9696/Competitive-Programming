/*Bismillahir rahmanir rahim*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[4];
    for(int i=0;i<4;i++)
    {
        cin>>a[i];
        //input : 2 1 1 3
    }

    /*size ber korar nium:*/

    int n = sizeof(a) / sizeof(a[0]);
    cout<<n;

    //output : 4
    //array sort korara built in function

    sort(a,a+4);

    //output : 1 1 2 3

    return 0;
}
