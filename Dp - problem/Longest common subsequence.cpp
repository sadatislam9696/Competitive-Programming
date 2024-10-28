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
const int N = 1e3 + 9;

string a, b; 
int dp[N][N];
int find_lcs(int i, int j){
   if(i >= a.size() or j >= b.size()) return 0;
   if(dp[i][j] != -1) return dp[i][j];
   int ans = find_lcs(i + 1, j);
   ans = max(ans, find_lcs(i, j + 1));

   if(a[i] == b[j]){
     ans = max(ans, 1 + find_lcs(i + 1, j + 1));
   }

   dp[i][j] =  ans;
   return ans;
}

void find_path(int i, int j){
    if(i >= a.size() or j >= b.size()) return;
    if(a[i] == b[j]){
       cout << a[i];
       find_path(i + 1, j + 1);
       return;
    }
    int l = find_lcs(i + 1, j);
    int r = find_lcs(i, j + 1);

    if(l <= r){
       find_path(i, j + 1);
    }
    else {
       find_path(i + 1, j);
    }

}
void solution(){
     cin >> a >> b; 
     memset(dp, -1, sizeof(dp));
     cout << find_lcs(0, 0) << nn;
     find_path(0, 0);
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
