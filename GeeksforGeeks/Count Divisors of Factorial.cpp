
/// https://www.geeksforgeeks.org/count-divisors-of-factorial/


/***   Bismillahir Rahmanir Rahim   ***/

#include<bits/stdc++.h>
using namespace std;

#define  nn  '\n'
using ll = long long;
const int N = 1e6;

bool p[N];
vector<int>v;
void seive_of_prime(){
    for(int i = 1; i <= N; i++){
        p[i] = true;
    }
    p[1] = false;
    for(int i = 2; 1LL * i * i <= N; i++){
       if(p[i]){
         for(int j = i + i; j <= N; j += i){
             p[j] = false;
         }
       }
    }

    for(int i = 1; i <= N; i++){
        if(p[i]){
            v.push_back(i);
        }
    }
}
ll legendre(int n, int p){
    ll ans = 0;
    while(n){
        ans += n / p;
        n /= p;
    }
    return ans;
}
void solution(){
    int n;
    cin >> n;

    map<int, int>cnt;
    for(auto it : v){
        if(it <= n){
            ll x = legendre(n, it);
            cnt[it] = x;
        }
    }

    ll ans = 1;
    for(auto it : cnt){
        ans *= (it.second + 1);
    }

    cout << ans << nn;
}

int32_t main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    seive_of_prime();

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
