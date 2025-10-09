
///   https://codeforces.com/contest/1633/problem/D


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
#define     yes         cout << "YES" << nn
#define     no          cout << "NO" << nn

using ll =  long long;
using ld =  long double;
using ull = unsigned long long;
const ld pi = acos(-1.0);
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int M = 1e9 + 7;
const int N = 1e3 + 9;

int op[N];
ll dp[N][12010];
int  b[N], c[N];
ll find_ans(int i, int n, int k){
    if(i >= n){
        if(i == n){
            if(op[b[i]] <= k)return c[i];
            return 0;
        }
        return 0;
    }
 
    if(dp[i][k] != -1)return dp[i][k];

    ll ans = 0; 
    if(op[b[i]] <= k){
        ans =  ans + find_ans(i + 1, n, k - op[b[i]]) + c[i];
    }
    ans = max(ans, find_ans(i + 1, n, k));

    return dp[i][k] = ans;
}
void solution(){
    int n, k; 
    cin >> n >> k; 
    
    k = min(k, 12010);
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }  
    for(int i = 1; i <= n; i++){
        cin >> c[i]; 
    }
    
    memset(dp, -1, sizeof(dp));
    cout << find_ans(1, n, k) << nn;

    for(int i = 1; i <= n; i++){
        c[i] = b[i] = 0;
    }
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    op[1] = 0;
    for(int i = 2; i < N; i++){
        op[i] = INT_MAX;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= i; j++) {
            if (i + i / j <= 1000) {
                //cout << i + i / j << ' ';
                op[i + i / j] = min(op[i + i / j], op[i] + 1);
            }
        }
    }

    int t = 1, c = 1;
    cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
