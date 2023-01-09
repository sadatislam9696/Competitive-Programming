#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        int Petya;
        int Vasya;
        int Tonya;

        cin>>Petya;
        cin>>Vasya;
        cin>>Tonya;

        if(Petya == 1 and Vasya ==1)
        {
            ans++;
        }
        else if(Tonya == 1 and Vasya ==1)
        {
            ans++;
        }
        else if(Petya == 1 and Tonya ==1)
        {
            ans++;
        }

    }

    cout<<ans<<"\n";

}
