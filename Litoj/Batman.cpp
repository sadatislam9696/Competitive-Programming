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

int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
int dy[]= { 0, 0,-1, 1, -1, 1,-1, 1};

const int mod = 1e9 + 7;
const int N = 55;

int dp[N][N][N];
string s, r, l;
int find_ans(int i, int j, int k){
    if(i >= s.size() or j >= r.size() or k >= l.size()){
        return 0;
    }
    if(dp[i][j][k] != -1)return dp[i][j][k];
    int ans = 0;
    if(s[i] == r[j] and r[j] == l[k]){
        ans = max(ans, 1 + find_ans(i + 1, j + 1, k + 1));
    }
    else{
        ans = max({ans, find_ans(i + 1, j, k),find_ans(i, j + 1, k), find_ans(i, j, k + 1)});
    }
    return dp[i][j][k] = ans;
}
void solution(){
   cin >> s >> r >> l;
   memset(dp, -1, sizeof dp);
   cout << find_ans(0, 0, 0) << nn;
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
