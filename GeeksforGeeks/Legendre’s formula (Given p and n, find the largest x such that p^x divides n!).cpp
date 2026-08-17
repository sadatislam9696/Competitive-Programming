///   https://www.geeksforgeeks.org/legendres-formula-highest-power-of-prime-number-that-divides-n/


/***   Bismillahir Rahmanir Rahim   ***/

#include<bits/stdc++.h>
using namespace std;

#define  nn  '\n'
using ll = long long;


void solution(){
   int n, p; 
   cin >> n >> p;

   ll ans = 0;
   while(n){
    ans += n / p;
    n /= p;
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
