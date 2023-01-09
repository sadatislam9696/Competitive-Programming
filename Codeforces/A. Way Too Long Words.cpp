#include<bits/stdc++.h>
using namespace std;

int main()
{

//
//    string str = "hello";
//    int len = str.size();
//
//    for(int i = 0; i < len; i++)
//    {
//      cout<<str[i]<<" \n";
//    }


    int n;
    cin>>n;

    for(int  i = 1; i <= n; i++)
    {
       string word;
       cin>>word;

       int len = word.size();
       if(len > 10)
       {
          char firstchar = word[0];
          char lastchar = word[len - 1];
          int remainchar = len - 2;
          cout<<firstchar<<remainchar<<lastchar<<"\n";

       }
       else cout<<word<<"\n";

    }

}
