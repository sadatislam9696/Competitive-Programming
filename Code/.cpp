#include<bits/stdc++.h>
using namespace std;
int main()
{

   int magic_num=5;
   int guess,guess_cnt=0;
   while(guess != magic_num)
   {
       cout<<"Enter one number : ";
       cin>>guess;
       guess_cnt++;
       if(guess_cnt==2)
       {
           break;
       }
       else
        continue;
   }

   if(guess==magic_num)
   {
       cout<<"Congrats you are legend ";
   }
   else
   {
       cout<<"Your guessing knowledge so poor  ";
   }

    return 0;

}
