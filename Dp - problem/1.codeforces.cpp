https://codeforces.com/contest/1509/problem/B

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
const int N = 2e3 + 9;

int a[N];
ll dp[N][N];
ll find_ans(int l, int r){
   if(l == r)return 0;
   if(dp[l][r] != -1)return dp[l][r];

   ll ans = a[r] - a[l];
   ans += min(find_ans(l + 1, r), find_ans(l, r - 1));
   
   dp[l][r] = ans;
   return dp[l][r];
}
void solution(){
   int n; 
   cin >> n; 
 
   for(int i = 1; i <= n; i++){
      cin >> a[i];
   }

   memset(dp, -1, sizeof(dp));
   sort(a + 1, a + n + 1);

   cout << find_ans(1, n) << nn;
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

