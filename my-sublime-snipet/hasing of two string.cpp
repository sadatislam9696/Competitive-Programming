/***   Bismillahir Rahmanir Rahim   ***/

#include<bits/stdc++.h>
using namespace std;

#define     nn          '\n'
#define     ss          second
#define     ff          first
#define     sp(d, n)    fixed << setprecision(d) << n
#define     srt(v)      sort(v.begin(),v.end());
#define     rsrt(v)     sort(v.rbegin(),v.rend());
#define     rev(v)      reverse(v.begin(),v.end());
#define     mem(a, x)   memset(a, x, sizeof a)

using ll =  long long;
using ld =  long double;
using ull = unsigned long long;
const ld pi = acos(-1.0);
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int M = 1e9 + 7;
const int N = 1e6 + 9;
const int mod = 1e9 + 7;

int p = 137;
int pw[N];
void pre(){
    pw[0] = 1;
    for(int i = 1; i < N; i++){
       pw[i] = 1LL * pw[i - 1] * p % mod;
    }
}
int hasing(string s){
    int n = s.size();
    int hs = 0;
    for(int i = 0; i < n; i++){
       hs += 1LL * s[i] * pw[i] % mod;
       hs %= mod;
    }
    return hs;
}
void solution(){
   string s, r; 
   cin >> s >> r; 
   cout << (hasing(s) == hasing(r)) << nn;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    pre();

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}

