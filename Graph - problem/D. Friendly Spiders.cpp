//    https://codeforces.com/contest/1775/problem/D  -  problem link

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

const int M = 6e5 + 9;
const int N = 3e5 + 9;

int spf[N];
int par[M], dis[M], vis[M];
void find_spf(){
    for(int i = 2; i < N; i++){
        spf[i] = i;
    }
    for(int i = 2; i < N; i++){
        for(int j = i; j < N; j += i){
            spf[j] = min(spf[j], i);
        }
    }
}

vector<int>adj[M];
void make_list(int n, int ind){
    set<int>s;
    while(n > 1){
        s.insert(spf[n]);
        n /= spf[n];
    }

    for(auto v : s){
        adj[N + v].push_back(ind);
        adj[ind].push_back(N + v);
    }
}
void solution(){
    int n;
    cin >> n; 

    int a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        make_list(a[i], i);
    } 

    int s, d; 
    cin >> s >> d; 

    queue<int>q; 
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v : adj[u]){
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
                par[v] = u;
                dis[v] = dis[u] + 1;
            }
        }
    }
    if(!vis[d]){
        cout << -1 << nn;
        return;
    }


    vector<int>ans;

    int p = d; 
    ans.push_back(d);
    while(p != s){
        //cout << par[p] << nn;
        if(par[p] <= N)ans.push_back(par[p]);
        p = par[p];
    }

    reverse(ans.begin(),ans.end());

    cout << ans.size() << nn;
    for(auto it : ans){
        cout << it << ' ';
    }
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    find_spf();

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
