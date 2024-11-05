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
const int N = 3009;

string s, r, ans;
int dp[N][N]; 
int find_ans(int i, int j){
    if(i >= s.size() or j >= r.size()){
       return 0;
    }
    if(dp[i][j] != -1)return dp[i][j];
    int ans = 0;
    if(s[i] == r[j]){
       ans = max(ans, 1 + find_ans(i + 1, j + 1));
    }
    else{
      ans = max(ans, find_ans(i + 1, j));
      ans = max(ans, find_ans(i, j + 1));
    }
    dp[i][j] = ans;
    return ans;
}
void print_path(int i, int j){
    if(i >= s.size() or j >= r.size()){
       return;
    }
    if(s[i] == r[j]){
       cout << s[i];
       print_path(i + 1, j + 1);
       return;
    }
    int x = find_ans(i + 1, j);
    int y = find_ans(i, j + 1);
    if(x <= y){
       print_path(i, j + 1);
    }
    else print_path(i + 1, j);
}

void solution(){
    cin >> s >> r;
    memset(dp, -1, sizeof dp);
    find_ans(0, 0);
    print_path(0, 0);
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

