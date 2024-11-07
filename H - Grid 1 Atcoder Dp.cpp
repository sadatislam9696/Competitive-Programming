#include<bits/stdc++.h>
using namespace std;
#define nn '\n'

const int N = 1e3 + 9;
const int mod = 1e9 + 7;

int n, m, dp[N][N];
char a[N][N];
int find_ans(int i, int j){
    if(i > n or j > m)return 0;
    if(i == n and j == m)return 1;
    if(a[i][j] == '#')return 0;
    if(dp[i][j] != -1)return dp[i][j];
    
    int ans = 0;
    ans = find_ans(i + 1, j);
    ans += find_ans(i, j + 1);
    ans %= mod;
    
    return dp[i][j] = ans;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << find_ans(1, 1) << nn;
    return 0;
}
