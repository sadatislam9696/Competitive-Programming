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
const int N = 1e5 + 9;

int sz[N];
vector<int>adj[N];
void dfs(int u, int p){
    sz[u] = 1;
    // base case no nedded when a node is not contain a child then dfs called end;
    for(auto v : adj[u]){
      if(v != p){
         dfs(v, u);
         sz[u] += sz[v]; // this line are major 
      }
    }
} 
void solution(){
     int n, m; 
     cin >> n >> m; 

     while(m--){
       int u, v; 
       cin >> u >> v; 
       adj[u].push_back(v);
       adj[v].push_back(u);
     }

     dfs(1, 0);
     for(int i = 1; i <= n; i++){
       cout << i << " : " << sz[i] << nn;
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
