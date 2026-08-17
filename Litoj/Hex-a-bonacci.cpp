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

const int mod = 10000007;
const int N = 1e4 + 9;

int a, b, c, d, e, f, n, dp[N];
int find_ans(int n){
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if(dp[n] != -1)return dp[n];
    ll x =  (find_ans(n-1) + find_ans(n-2)) % mod;
    x = (x + find_ans(n-3)) % mod;
    x = (x + find_ans(n-4)) % mod;
    x = (x + find_ans(n-5)) % mod;
    x = (x + find_ans(n-6)) % mod;
    return dp[n] = x;
}
void solution(){
    cin >> a >> b >> c >> d >> e >> f >> n;
    memset(dp, -1, sizeof dp);
    cout << find_ans(n) % mod << nn;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    cin >> t;
    //cin.ignore();
    while(t--){
        cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
