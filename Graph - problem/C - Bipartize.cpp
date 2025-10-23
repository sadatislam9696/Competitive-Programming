//https://atcoder.jp/contests/abc427/tasks/abc427_c



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

void solution(){
    int n, m; 
    cin >> n >> m; 
    
    vector<pair<int, int>>adj;
    for(int i = 1; i <= m; i++){
        int u, v; 
        cin >> u >> v; 
        adj.push_back({u - 1, v - 1});
    }

    int ans = m; 
    for(int mask = 0; mask < (1 << n); mask++){
        int cnt = 0; 
        for(auto it : adj){
            int x = ((mask >> it.ff) & 1);
            int y = ((mask >> it.ss) & 1);
            if(x == y){
                cnt++;
            }
        }
        ans = min(ans, cnt);
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
