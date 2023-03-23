#include<bits/stdc++.h>
using namespace std;
int main()
{
  int siz;
  cin>>siz;
  int a[siz];
  for(int a_index=0;a_index<siz;a_index++)
  {
      cin>>a[a_index];
  }
  int b[siz];
  int b_index=0;
  for(int a_index=siz-1;a_index>=0;a_index-- )
  {
      b[b_index]=a[a_index];
      b_index++;
  }
  for(int  b_index=0; b_index<siz; b_index++)
    cout<<b[b_index]<<' ';

    return 0;
    /* prothome a name ekta array nichi. a array er element gula input
    nilam .tarpor b name ekta array nilam tarpor ekta loop calailam
    a array er ulta dikh theke a array er man gula b array te assign korlam
    tarpor b array er element gula print korlam*/

}
