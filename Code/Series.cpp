#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num,sum=0,i;
    cout<<"Enter last value : ";
    cin>>num;

    for(i=1;i<=num;i=i+1)
    {
        sum = sum +pow(i,2);////(1pow2 +2pow2+ 3pow3....npown)
    }
     cout<<sum;

}
