//https://atcoder.jp/contests/abc401/tasks/abc401_e



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
const int N = 4e5 + 9;

int pa[N], sz[N];
void make(){
    for(int i = 1; i < N; i++){
        pa[i] = i; 
        sz[i] = 1;
    }
}
int Find(int x){
    if(pa[x] == x)return x; 
    return pa[x] = Find(pa[x]);
}

void Union(int x, int y){
    int a = Find(x); 
    int b = Find(y);
    if(a != b){
        pa[a] = b; 
        sz[b] += sz[a];
    }
}

vector<int>adj[N];
void solution(){
    int n, m; 
    cin >> n >> m; 

    for(int i = 1; i <= m; i++){
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }

    make();

    set<int>s; 
    for(int i = 1; i <= n; i++){
        if(s.find(i) != s.end()){
            s.erase(i);
        }
        for(auto v : adj[i]){
            if(v < i){
                Union(i, v);
            }
            else s.insert(v);
        }
        if(sz[Find(1)] == i){
            cout << s.size() << nn;
        }
        else cout << -1 << nn;
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
