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
const int N = 4009;

string s; 
vector<int>adj[N];
int ans, white[N], black[N];
void dfs(int u, int p){
    if(s[u - 1] == 'W')white[u]++;
    else black[u]++;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            white[u] += white[v];
            black[u] += black[v];
        }
    }

    if(white[u] == black[u])ans++;
}
void solution(){
    int n; 
    cin >> n;
    int a[n + 1];
    a[1] = -1;
    for(int i = 2; i <= n; i++){
        cin >> a[i];
    }

    cin >> s;
    for(int i = 1; i <= n; i++){
        //cout << a[i] << ' ' << i << nn;
        adj[a[i]].push_back(i);
        adj[i].push_back(a[i]); 
    }
    // for(int i = 1; i <= n; i++){
    //     cout << i << ':';
    //     for(auto it : adj[i]){
    //         cout << it << ' ';
    //     }
    //     cout << nn;
    // }
    
    dfs(1, -1);
    cout << ans << nn;
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        white[i] = black[i] = 0;
    }
    ans = 0;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    cin >> t;
    //cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}

