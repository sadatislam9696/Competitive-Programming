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
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

int p1 = 137, p2 = 277; 
int pw1[N], pw2[N];

void pre(){
    pw1[0] = 1;
    for(int i = 1; i < N; i++){
        pw1[i] = 1LL * pw1[i - 1] * p1 % mod1;
    }
    pw2[0] = 1;
    for(int i = 1; i < N; i++){
        pw2[i] = 1LL * pw2[i - 1] * p2 % mod2;
    }
}
pair<int, int> hasing(string s){
    int n = s.size();
    int hs1 = 0;
    for(int i = 0; i < n; i++){
        hs1 += 1LL * s[i] * pw1[i] % mod1;
        hs1 %= mod1;
    }
    int hs2 = 0;
    for(int i = 0; i < n; i++){
        hs2 += 1LL * s[i] * pw2[i] % mod2;
    }
    return {hs1, hs2};
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

