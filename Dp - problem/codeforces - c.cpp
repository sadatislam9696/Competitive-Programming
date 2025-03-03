// https://codeforces.com/contest/1513/problem/C


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
const int N = 2e5 + 9;

ll dp[12][N];
ll find_ans(int n, int m){
   if(m == 0)return 1; 
   if(dp[n][m] != -1)return dp[n][m];
   
   ll ans = 0;
   if(n == 9){
      return dp[n][m] =  find_ans(1, m - 1) + find_ans(0, m - 1) % M;
   }
   return dp[n][m] = find_ans(n + 1, m - 1) % M;

   // dp[n][m] = ans;
   // return dp[n][m];
}
void solution(){
  string s;
  int m; 

  cin >> s >> m; 

  ll ans = 0;
  for(auto it : s){
    int x = it - '0';
    ans += find_ans(x, m) % M;
    ans %= M;
  }
  cout << ans << nn;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    cin >> t;
    //cin.ignore();
    memset(dp, -1, sizeof(dp));
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}

