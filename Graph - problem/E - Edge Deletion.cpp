/// https://atcoder.jp/contests/abc243/tasks/abc243_e



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

const int N = 300 + 7;
const ll inf = 1e18;

ll a[N][N] = {0};
void solution(){
    int n, m; 
    cin >> n >> m; 

    vector<pair<pair<int, int>, ll>>adj;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j){
                a[i][j] = inf;
            }
            else a[i][j] = 0;
        }
    }
    for(int i = 1; i <= m; i++){
        ll u, v, c; 
        cin >> u >> v >> c;

        adj.push_back({{u, v}, c});

        a[u][v] = c; 
        a[v][u] = c;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][k] != inf and a[k][j] != inf){
                    a[i][j] = min(a[i][j], 1ll * a[i][k] + a[k][j]);
                }
            }
        }
    }

    ll ans = 0; 
    for(auto it : adj){
        int u = it.ff.ff; 
        int v = it.ff.ss; 
        ll c = it.ss;

        int unused = 0;
        for(int i = 1; i <= n; i++){
            if(i != u and i != v and 1LL * a[u][i] + a[i][v] <= c){
                unused = 1;
            }
        }
        ans += unused;
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
