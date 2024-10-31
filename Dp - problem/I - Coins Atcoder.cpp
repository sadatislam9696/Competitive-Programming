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
const int N = 2999 + 9;

double p[N], n;
double dp[N][N];
bool vis[N][N];
double find_more_head(int i, int head, int tail){
    if(i == n + 1){
        if(head > tail)return 1;
        else return 0;
    }
    if(vis[i][head]){
        return dp[i][head];
    }
    vis[i][head] = 1;
    double ans = p[i] * find_more_head(i + 1, head + 1, tail);
    ans += (1 - p[i]) * find_more_head(i + 1, head, tail + 1);
    dp[i][head] = ans;
    return ans;
}
void solution(){
     cin >> n; 
     for(int i = 1; i <= n; i++){
        cin >> p[i];
     }

     cout << fixed << setprecision(10) << find_more_head(1, 0, 0) << nn;
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
