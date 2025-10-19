//problem link  :            https://atcoder.jp/contests/abc428/tasks/abc428_e



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

vector<int>adj[N];
int deg[N], dis[N];
int  dis1[N], ans[N];

void dfs(int u, int p){
    for(auto v : adj[u]){
        if(v != p){
            dis[v] = dis[u] + 1;
            dfs(v, u);
        }
    }
}
void solution(){
    int n;
    cin >> n; 
    
    for(int i = 1; i <= n; i++){
        int u, v; 
        cin >> u >> v; 
        deg[u]++;
        deg[v]++;
     
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  
    

    dfs(1, -1);
    
    int mx = -1, node = 1; 
    for(int i = 1; i <= n; i++){
        if(dis[i] > mx or (dis[i] == mx and i > node)){
            mx = dis[i];
            node = i;
        }
        //cout << dis[i] << ' ';
        dis[i] = 0;
    } //cout << nn;


    dfs(node, -1);

    mx = -1;
    int node2 = 0;
    for(int i = 1; i <= n; i++){
        if(dis[i] > mx or (dis[i] == mx and i > node2)){
            mx = dis[i]; 
            node2 = i;
        }
        dis1[i] = dis[i];
        dis[i] = 0;
    }
    
    dfs(node2, -1);
    //cout << node << ' ' << node2 << nn;

    for(int i = 1; i <= n; i++){
        int x = dis1[i], y = dis[i];
        int mx = max(x, y);

        if(mx == x and mx == y){
            ans[i] = max(node, node2);
        }
        else if(mx == x){
            ans[i] = node;
        }
        else ans[i] = node2;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << nn;
    }
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
