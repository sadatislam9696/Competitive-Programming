///  https://www.geeksforgeeks.org/gcd-of-two-numbers-when-one-of-them-can-be-very-large-2/

/***   Bismillahir Rahmanir Rahim   ***/

#include<bits/stdc++.h>
using namespace std;

#define  nn  '\n'
using ll = long long;

void solution(){
    ll a; cin >> a; 
    string s; cin >> s; 

    ll ans = 0;
    for(int i = 0; i < s.size(); i++){
        ans = (ans * 10L % a + (s[i] - '0')) % a;
    }

    int x = __gcd(ans, a);
    cout << x << nn;
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
