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
const int N = 105;

string s, r;
bool vis[N][N];
string dp[N][N];
string find_ans(int i, int j){
    if(i >= s.size() or j >= r.size()){
        return "";
    }
    if(vis[i][j])return dp[i][j];
    string ans = "";
    if(s[i] == r[j]){
        ans = string(1, s[i]) + find_ans(i + 1, j + 1);
    }
    else{
        string x = find_ans(i, j + 1);
        string y = find_ans(i + 1, j);
        if(x.size() < y.size()){
            ans = y;
        }
        else if(x.size() > y.size()){
            ans = x;
        }
        else ans = min(x, y);
    }
    vis[i][j] = true;
    dp[i][j] = ans;
    return ans;
}
void solution(){
    cin >> s >> r;
    string ans = find_ans(0, 0);
    memset(vis, false, sizeof vis);
    if(ans.empty()){
        cout << ":(" << nn;
    }
    else cout << ans << nn;
}
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t = 1, c = 1;
    cin >> t;
    while(t--){
        cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
