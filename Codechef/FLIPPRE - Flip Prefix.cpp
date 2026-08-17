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
#define     yes         cout << "YES" << nn
#define     no          cout << "NO" << nn

using ll =  long long;
using ld =  long double;
using ull = unsigned long long;
const ld pi = acos(-1.0);
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int M = 1e9 + 7;
const int N = 62;

int n;
string s;
int dp[N][120];
int find_ans(int i, int cnt0, int cnt1){
   if(i == n){
     return 1;
   }
   
   if(dp[i][cnt0 + cnt1] != -1)return dp[i][cnt0 + cnt1];

   int ans = 0;
   if(s[i] == '1'){
     int x = cnt0, y = cnt1 + 1;
     if(x == y){
        ans += find_ans(i + 1, cnt0, cnt1 + 1) + find_ans(i + 1, cnt0, cnt1 + 1);
     }
     else  ans += find_ans(i + 1, cnt0, cnt1 + 1);
   }
   else{
     int x = cnt0 + 1, y = cnt1;
     if(x == y){
         ans += find_ans(i + 1, cnt0 + 1, cnt1) + find_ans(i + 1, cnt0 + 1, cnt1);
     }
     else ans += find_ans(i + 1, cnt0 + 1, cnt1);
   }

   return dp[i][cnt0 + cnt1] = ans;
}
void solution(){
   cin >> n;
   cin >> s; 

   memset(dp, -1, sizeof(dp));
   cout << find_ans(0, 0, 0) << nn;
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
