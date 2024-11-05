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

const ll inf = 1e11 + 9;
const int M = 1e9 + 7;
const int N = 105;

int n, cap, w[N], v[N];
ll dp[N][N * 1000];
ll find_ans(int i, int tot_value){
    if(i == n + 1){
      if(tot_value == 0){
        return 0;
      }
      return inf;
    }
    if(dp[i][tot_value] != -1)return dp[i][tot_value];
    ll ans = inf;
    ans = find_ans(i + 1, tot_value);
    ans = min(ans, w[i] + find_ans(i + 1, tot_value - v[i]));
    dp[i][tot_value] = ans;
    return ans; 
}
void solution(){
     cin >> n >> cap;
     for(int i = 1; i <= n; i++){
       cin >> w[i] >> v[i];
     }
     memset(dp, -1, sizeof dp);

     int ans = 0;
     for(int v = 1; v <= (n * 1000); v++){
        if(find_ans(1, v) <= cap){
          ans = max(ans, v);
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

