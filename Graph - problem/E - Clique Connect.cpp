
//  https://atcoder.jp/contests/abc352/tasks/abc352_e   - problem link

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
const int N = 5e5 + 9;

int vis[N];
vector<pair<ll, int>>adj[N];

void solution(){
    int n, m; 
    cin >> n >> m; 
    
    int deg[n + 1] = {0}, com = n; 
    int first_node = 1, flag = 0;

    for(int i = 1; i <= m; i++){
        ll k, c; 
        cin >> k >> c; 

        for(int j = 1; j <= k; j++){
            int u; 
            cin >> u;
            if(deg[u] == 0)com--;
            deg[u] = 1;

            if(!flag){
                first_node = u; 
                flag = 1;
            }

            adj[n + i].push_back({c, u});
            adj[u].push_back({c, n + i});
        }
    }
    if(com >= 1){
        cout << -1 << nn;
        return;
    }

    ll ans = 0; 
    minHeap<pair<ll, int>>q; 
    q.push({0, first_node});

    while(!q.empty()){
        ll c = q.top().ff;
        int u = q.top().ss; 

        q.pop();

        if(vis[u])continue;
        vis[u] = 1;
        if(u <= n) ans += 1ll * c;

        for(auto it : adj[u]){
            if(!vis[it.ss]){
                q.push(it);
            }
        }
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
