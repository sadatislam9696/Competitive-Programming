/// https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/


/***   Bismillahir Rahmanir Rahim   ***/

#include<bits/stdc++.h>
using namespace std;

#define  nn  '\n'
using ll = long long;


void solution(){
   int n; 
   cin >> n; 

   int i = 5;
   ll ans = 0;
   while(n / i > 0){
     ans += n / i;
     i *= 5;
   }

   cout << ans << nn;
} 

int32_t main(){
   
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
