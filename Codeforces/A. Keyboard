#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    string ache = {"qwertyuiopasdfghjkl;zxcvbnm,./"};
    
    //s1 = qwertyuiop
    //s2 = asdfghjkl;
    //s3 = ;zxcvbnm,./
    
    string s,rl;
    cin>>rl;
    cin>>s;

    for(int i=0; i<s.size(); i++)
    {
        for(int j=0; j<ache.size(); j++)
        {
            if(s[i]==ache[j])
            {
                if(rl[0]=='R')
                {
                    cout<<ache[j-1];
                }
                else
                    cout<<ache[j+1];
            }
        }
    }


    return 0;
}
