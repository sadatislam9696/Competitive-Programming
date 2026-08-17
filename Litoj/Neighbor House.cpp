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
const int N = 25;

int n, a[N], b[N], c[N], dp[N][3];
int find_ans(int i, int last){
  if(i == n + 1){
    return 0;
  }
  if(dp[i][last] != -1)return dp[i][last];
  int ans = INT_MAX;
  for(int j = 1; j <= 3; j++){
     if(j == last)continue;
     if(j == 1) ans = min(ans, a[i] + find_ans(i + 1, j));
     if(j == 2) ans = min(ans, b[i] + find_ans(i + 1, j));
     if(j == 3) ans = min(ans, c[i] + find_ans(i + 1, j));
  }
  dp[i][last] = ans;
  return ans;
}
void solution(){
    cin >> n; 
    for(int i = 1; i <= n; i++){
      cin >> a[i] >> b[i] >> c[i];
    }
    memset(dp, -1, sizeof dp);

    cout << find_ans(1, 5) << nn; 
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

