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

const int inf = 1e9 + 10;
const int M = 1e9 + 7;
const int N = 1e2 + 9;

int n, m, a[N][N], dp[N][N];
int find_ans(int i, int j){
   if(i > n or j > m) return inf;
   if(i == n and j == m)return a[i][j];
   if(dp[i][j] != -1)return dp[i][j];
   int ans = a[i][j] + min(find_ans(i + 1, j), find_ans(i, j + 1));
   dp[i][j] = ans;
   return ans;
}

void find_path(int i, int j){
   cout << i << " " << j << nn;
   if(i == n and j == m) return;
   int l = find_ans(i + 1, j);
   int r = find_ans(i, j + 1);

   if(l <= r){
      find_path(i + 1, j);
   }
   else find_path(i, j + 1);
}
void solution(){
   cin >> n >> m; 
   memset(dp, -1, sizeof(dp));
   for(int i = 1; i <= n; i++){
     for(int j = 1; j <= n; j++){
       cin >> a[i][j];
     }
   }

   cout << find_ans(1, 1) << nn;
   find_path(1, 1);
   
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



 
