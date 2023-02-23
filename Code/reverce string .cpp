#include<bits/stdc++.h>
using namespace std;
int main()
{

   {

    char str1[99],str2[99];
    gets(str1);
    /*sadat islam
      malsi tadas*/
    int l=strlen(str1),i,j;

    for(j=0,i=l-1; i>=0; j++,i--)
    {
        str2[j]=str1[i];
    }
    str2[j]='\0';

    cout<<str2;
   }
//////////////////////////////////////////
/////////another

   {

    string str1,str2;
    cin>>str1;
    reverse(str1.begin(),str1.end());
    cout<<str1;

    /*input  : sadat
    output : tadas*/
   }

    return 0;
}
