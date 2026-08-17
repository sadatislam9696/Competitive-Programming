
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
const int N = 1009;

vector<int>adj[N];
vector<int>vis(N);
int cnt[N];

void solution(){
   int k, n, m;
   cin >> k >> n >> m;

   int a[k + 1];
   for(int i = 1; i <= k; i++){
     cin >> a[i];
   }
   while(m--){
     int u, v;
     cin >> u >> v;
     adj[u].push_back(v);
   }

   for(int i = 1; i <= k; i++){
      for(int i = 1; i <= n; i++){
         vis[i] = 0;
      }
      queue<int>q;
      q.push(a[i]);
      vis[a[i]] = 1;

      while(!q.empty()){
         int u = q.front();
         q.pop();
         cnt[u]++;
         for(auto v : adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
         }
      }
   }

   int ans = 0;
   for(int i = 1; i <= n; i++){
      //cout << cnt[i] << ' ';
      if(cnt[i] >= k) ans++;
   }

   cout << ans << nn;
   for(int i = 1; i <= n; i++){
     adj[i].clear();
     cnt[i] = 0;
     a[i] = 0;
     vis[i] = 0;
   }
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    cin >> t;
    //cin.ignore();
    while(t--){
        cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
