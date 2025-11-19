//        https://codeforces.com/gym/105925/problem/F


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

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int dx[6] = {0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 1, -1};

const int M = 1e9 + 7;
const int N = 1e3 + 9;

int a[N], n;
ll dp[N][9009][5];
ll find_ans(int i, int sum, int cnt) {
    if(sum < 0) {
        return 0;
    }
    if(i == n + 1) {
        if(sum == 0 and cnt == 0) {
            return 1;
        }
        return 0;
    }

    if(dp[i][sum][cnt] != -1) {
        return dp[i][sum][cnt];
    }

    ll ans = 0;
    if(cnt) {
        ans += 1LL * find_ans(i + 1, sum - a[i], cnt - 1);
    }
    ans += 1LL * find_ans(i + 1, sum, cnt);
    return dp[i][sum][cnt] = ans;
}
void solution() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += 1000;
    }

    memset(dp, -1, sizeof(dp));

    int q;
    cin >> q;
    while(q--) {
        int sum;
        cin >> sum;
        sum += 4000;
        cout << find_ans(1, sum, 4) << nn;
    }
}
int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1, c = 1;
    //cin >> t;
    //cin.ignore();
    while(t--) {
        //cout << "Case " << c++ << ": ";
        solution();
    }
    return 0;
}
