///  https://atcoder.jp/contests/abc302/tasks/abc302_f    - problem link


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
const int N = 5e6 + 9;

vector<int>adj[N];
int dis[N], vis[N];
void solution(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int sz;
        cin >> sz;

        vector<int>v;
        int cur = i + m + 3, flag = 0, last = 0;
        for(int j = 1; j <= sz; j++){
            int val;
            cin >> val;
            if(val == 1)flag = 1;
            if(val == m)last = 1;
            v.push_back(val);
        }
        if(last){
            for(auto it : v){
                adj[m + 2].push_back(it);
                adj[it].push_back(m + 2);
            }
        }
        if(flag){
            for(auto it : v){
                adj[m + 1].push_back(it);
                adj[it].push_back(m + 1);
            }
        }
        else{
            for(auto it : v){
                adj[cur].push_back(it);
                adj[it].push_back(cur);
            }
        }
    }

    queue<int>q;
    q.push(1);
    vis[1] = 1;
    dis[1] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v : adj[u]){
            if(!vis[v]){
                dis[v] = dis[u] + 1;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    
    if(!vis[m]){
        cout << -1 << nn;
    }
    else{
        dis[m] -= 2;
        cout << dis[m] / 2 << nn;
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
