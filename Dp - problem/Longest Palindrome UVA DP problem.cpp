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
const int N = 1009;

string s;
int dp[N][N];
int find_ans(int i, int j){
    if(i > j)return 0;
    if(i == j)return 1;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = 0;
    if(s[i] == s[j]){
        ans = 2 + find_ans(i + 1, j - 1);
    }
    else{
        ans = max(find_ans(i + 1, j), find_ans(i, j - 1));
    }
    return dp[i][j] = ans;
}
void solution(){
   getline(cin, s);
   int n = s.size();
   memset(dp, -1, sizeof dp); 
   cout << (find_ans(0, n - 1)) << nn;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    cin >> t;
    cin.ignore();
    while(t--){
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
