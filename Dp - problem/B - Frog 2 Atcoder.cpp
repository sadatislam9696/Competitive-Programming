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

const int mod = 10000007;
const int N = 1e5 + 9;
const int inf = 1e9;

int n, k, h[N], dp[N];
int find_ans(int i){
    if(i > n)return inf;
    if(i == n)return 0;
    if(dp[i] != -1)return dp[i];
    int ans = abs(h[i] - h[i + 1]) + find_ans(i + 1);
    for(int j = 2; j <= k; j++){
        ans = min(ans, abs(h[i] - h[i + j]) + find_ans(i + j));
    }
    return dp[i] = ans;
}
void solution(){
    cin >> n >> k;
    //memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    //cout << find_ans(1) << nn;

    for(int i = 1; i <= n; i++){
        int ans = abs(h[i] - h[i - 1]) + dp[i - 1];
        for(int j = 2; j <= k; j++){
            if(i == 1){
                dp[i] = 0;
            }
            else{
                if(i - j >= 1)ans = min(ans, abs(h[i] - h[i - j]) + dp[i - j]);
                dp[i] = ans;
            }
        }
    }
    cout << dp[n] << nn;
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
