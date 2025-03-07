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

const int inf = 1e9 + 9;
const int M = 1e9 + 7;
const int N = 1e5 + 9;

int n, m, dis[N];
vector<int>adj[N];
int dp[N];
int find_ans(int u, int p){
    if(dp[u] != -1)return dp[u];
    if(adj[u].empty())return 0;
    int ans = 0;
    for(auto v : adj[u]){
        ans = max(ans, 1 + find_ans(v, u));
    }
    dp[u] = ans;
    return ans;
}
void solution(){
    cin >> n >> m; 
    for(int i = 1; i <= m; i++){
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
    }
    memset(dp, -1, sizeof dp);
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
       ans = max(ans, find_ans(i, 0));
    }
    cout << ans << nn;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
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

